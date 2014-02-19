%{
using namespace std;

#include <string>
// global temp fix for outfile
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include "driver.h"
#include "icstruct.h"

%}
%start start
%code requires {#include "ast.h" }
%union {
    char * istr;
    int iint;
    float ifloat;
    ASTNode_Base *inode;
    Addr *iaddr;
    vector<ASTNode_Base*> *multi_expr;
    vector<ASTNode_Assignment*> *multi_decl;
    vector<ASTNode_Val*> *multi_val;
	vector<Addr*> *multi_addr;
    ArrayIndex  *index;
    Array_Type *arraytype;
    ASTNode_Function *func;
    Scope* scope;
    Ctype* cast;
};

%token COMMAND ASSIGN ENDLINE PRINT SEPARATOR ARRAY_LEFT ARRAY_RIGHT METHOD_OP DEFINE DECLARE
%token BR_START BR_END AND NOT OR ARRAYINDEX IF ELSE BREAK RETURN
%token WHILE_LOOP FOR_LOOP ARRAY STRING
%token OPENP CLOSEP NEGATIVE
%token SUB ADD MULT DIV MOD CARET
%token <istr> TYPE COMPARE STATIC_STRING
%token <istr> ID COASSIGN BUILT_IN_FUNC
%token <iint> STATIC_INT
%token <ifloat> STATIC_FLOAT
%token <istr> STATIC_CHAR
%type <inode> expr selection stmt loop open_stmt decl block true_stmt
%type <inode> non_end_stmt declarations null_stmt null_expr fun_definition fun_declaration
%type <inode> block_stmt
%type <multi_expr> multi_expr multi_stmt function_args
%type <cast> type_cast
%type <multi_decl> multi_decl
%type <multi_val> function_paras function_para
%nonassoc CLOSEP
%nonassoc ELSE
%right ASSIGN COASSIGN
%left OR
%left AND
%nonassoc COMPARE
%left SUB ADD
%left MULT DIV MOD
%right CARET
%nonassoc UMINUS NOT
%nonassoc ARRAY_LEFT ARRAY_RIGHT

%%

start:
  start true_stmt {
        try {
            $2->toIC();
        } catch (const char* e) {
            yyerror(e);
        }
    }
  | start fun_definition {
        try {
            $2->toIC();
        } catch (const char* e) {
            yyerror(e);
        }
  }
  | start fun_declaration {
        try {
            $2->toIC();
        } catch (const char* e) {
            yyerror(e);
        }
  }
  | ENDLINE {}
  | {}
  ;
block_stmt:
    true_stmt { $$=$1; }
    | fun_definition { $$=$1; }
    ;
true_stmt:
    stmt ENDLINE {
        $$=$1;
    }
    | non_end_stmt {
        $$=$1;
    }
    ;
non_end_stmt:
    block {$$=$1;}
    | selection {$$=$1;}
    | loop {$$=$1;}
    | declarations {$$=$1;}
    ;
stmt:
  expr {
        $$=$1;
    }
  | PRINT expr multi_expr{
    $3->push_back($2);
        ASTNode_Base* a=new ASTNode_Print($3);
        $$=a;
  }
    | BREAK {
    $$=new ASTNode_Break(currScopes);}
    | RETURN expr {
        $$=new ASTNode_Return($2,currScopes);
    }
    ;
type_cast:
    TYPE {
        Ctype *t=new Ctype();
        t->d=0;
        if (string($1)=="int")
            t->t=VINT;
        else if (string($1)=="char")
            t->t=VCHAR;
        $$=t;
    }
    | ARRAY OPENP TYPE CLOSEP {
        Ctype *t=new Ctype();
        t->d=1;
        if (string($3)=="int")
            t->t=VINT;
        else if (string($3)=="char")
            t->t=VCHAR;
        $$=t;
    }
    | STRING {
        $$=new Ctype(VCHAR,1);
    }

declarations:
    type_cast multi_decl ENDLINE {
        for (unsigned i=0;i<$2->size();) {
            ASTNode_Val *j=(*$2)[i]->val();
            if (j->addr()==0) {
                Addr* a;
                if ($1->d==0) {
                    a=new Addr(getID());
                } else {
                    a=new Addr(getArrayID());
                    cout<<"ar_set_siz "<<a->value<<" 0\n";
                }
                a->d=$1->d;
                a->type=$1->t;
                j->setAddr(a);

            }
            if ($2->at(i)->source()==0) {
                $2->erase($2->begin()+i);
            } else {
                i++;
            }
        }
        $$=new ASTNode_Multi_Assignment($2);
    }
fun_declaration:
	DECLARE type_cast ID OPENP {
		if(currScopes->back() != globalScope) {
				yyerror("Attempting to declare function '" + string($3) + "' outside of global scope!");
		}
		Scope* newScope=new Scope(getScopeID());
        currScopes->push_back(newScope);
		Addr* a;
		if ($2->d==0) {
			a=new Addr(getID());
		} else {
			a=new Addr(getArrayID());
		}
        a->type=$2->t;
        a->d=$2->d;
        ASTNode_Function* func=new ASTNode_Function($3,0,a,0,newScope,currScopes);
		functions.push_back(func);
        newScope->assoc_func=func;
		$<func>$=func;
	}
	function_para{
		for (unsigned i=0;i<functions.size();i++) {
			if (functions[i]->getName()==$3) {
				vector<ASTNode_Val*> args= *(functions[i]->Args());
				if (args.size()!=$6->size())
					continue;
				for (unsigned j=0;j<args.size();j++) {
					if (args[j]->addr()->type != $6->at(j)->addr()->type || args[j]->addr()->d != $6->at(j)->addr()->d || !functions[i]->defined)
						continue;
                	yyerror("re-declaring function");
				}
            }
		}
		$<func>5->setArgs($6);	
	}
	CLOSEP ENDLINE {
        removeScope(currScopes,$<func>5->getScope());
		$$=new ASTNode_Dummy();
	}	
fun_definition:
    DEFINE type_cast ID OPENP {
			if(currScopes->back() != globalScope) {
				yyerror("Attempting to define function '" + string($3) + "' outside of global scope!");
			}
        Scope* newScope=new Scope(getScopeID());
        currScopes->push_back(newScope);

        
		Addr* a;
		if ($2->d==0) {
			a=new Addr(getID());
		} else {
			a=new Addr(getArrayID());
		}
        a->type=$2->t;
        a->d=$2->d;
        ASTNode_Function* func=new ASTNode_Function($3,0,a,0,newScope,currScopes);
        newScope->assoc_func=func;
        $<func>$=func;
    }
    function_para {
		bool exist=false;
		ASTNode_Function* f;
		for (unsigned i=0;i<functions.size();i++) {
            if (functions[i]->getName()==$3) {
				vector<ASTNode_Val*> args= *(functions[i]->Args());
				unsigned count=0;
				if (args.size()!=$6->size())
					continue;
				for (unsigned j=0;j<args.size();j++) {
					if (args[j]->addr()->type == $6->at(j)->addr()->type &&
						args[j]->addr()->d == $6->at(j)->addr()->d)
							count++;
					if (args[j]->addr()->type != $6->at(j)->addr()->type || args[j]->addr()->d != $6->at(j)->addr()->d || !functions[i]->defined)
						continue;
                	yyerror("re-definning function");
				}
				if (count==args.size()) {
					if (functions[i]->addr()->type!=$2->t ||
						functions[i]->addr()->d!=$2->d) {
						yyerror("Attempting to define function '"+functions[i]->getName()+"', with return type '"+findType($<func>5->addr())+"' but previously declared as type '"+findType(functions[i]->addr())+"'.");
					}
					exist=true;
					functions[i]->defined=true;
					f=functions[i];
				}
            }
        }
		if (exist) {
			removeScope(currScopes,$<func>5->getScope());
			currScopes->push_back(f->getScope());
			$<func>5=f;
		} else {
        	$<func>5->setArgs($6);
			$<func>5->defined=true;
        	functions.push_back($<func>5);
		}
		cout<<"jump end_function_"<<$<func>5->getScope()->id<<$3<<endl;
        cout<<"function_"<<$<func>5->getScope()->id<<$3<<":"<<endl;
    }
    CLOSEP {}
    open_stmt {
        $10->toIC();
        removeScope(currScopes,$<func>5->getScope());
        $<func>5->setBlock($10);
		printMessage("WARNING: there is no return value for function:"+string($3));
		cout<<"ret"<<endl;
        cout<<"end_function_"<<$<func>5->getScope()->id<<$3<<":"<<endl;
        $$=new ASTNode_Dummy();
    }
    ;
function_para:
	function_paras {$$=$1;}
	| {$$=new vector<ASTNode_Val*>();}
function_paras:
    function_paras SEPARATOR type_cast ID {
        checkRedefine($4);
		Addr* a;
		if ($3->d!=0) {
			a=new Addr(getArrayID());
		} else {
			a=new Addr(getID());
		}
        a->d=$3->d;
        a->type=$3->t;
        ASTNode_Val* v=new ASTNode_Val($4);
        v->setAddr(a);
        v->setScope(currScopes->back());
        vtable->add(v);
        $1->push_back(v);
        $$=$1;
    }
    | type_cast ID {
        checkRedefine($2);
		Addr *a;
		if ($1->d!=0) {
			a=new Addr(getArrayID());
		} else {
			a=new Addr(getID());
		}
        a->d=$1->d;
        a->type=$1->t;
        vector<ASTNode_Val*> *args=new vector<ASTNode_Val*>();
        ASTNode_Val* v=new ASTNode_Val($2);
        v->setAddr(a);
        v->setScope(currScopes->back());
        args->push_back(v);
        vtable->add(v);
        $$=args;
    }
loop:
    WHILE_LOOP OPENP expr CLOSEP {
        Scope* newScope=new Scope(getScopeID());
        currScopes->push_back(newScope);
        $<scope>$=newScope;

    }
    true_stmt{
        removeScope(currScopes,$<scope>5);
        $$=new ASTNode_While($3,$6,currScopes,$<scope>5);
    }
    | FOR_LOOP OPENP {
        Scope* newScope=new Scope(getScopeID());
        currScopes->push_back(newScope);
        $<scope>$=newScope;
    }
    null_stmt ENDLINE  null_expr ENDLINE null_stmt {}
    CLOSEP open_stmt {
        removeScope(currScopes,$<scope>3);
        $$=new ASTNode_For($4,$6,$8,$11,currScopes,$<scope>3);
    }
    ;
null_stmt:
    stmt {$$=$1;}
    | {$$=0;}
null_expr:
    expr {$$=$1;}
    | {$$=0;}

selection:
    IF OPENP expr CLOSEP open_stmt {
        $$=new ASTNode_If_Else($3,$5,0);
    }
    | IF OPENP expr CLOSEP open_stmt ELSE open_stmt {
        $$=new ASTNode_If_Else($3,$5,$7);
    }
    ;

open_stmt:
    true_stmt {$$=$1;}
    | ENDLINE {$$=0;}
    ;

block:
     BR_START  {
        Scope* newScope=new Scope(getScopeID());
        $<scope>$ = newScope;
        currScopes->push_back(newScope);
    }
     multi_stmt BR_END {
        removeScope(currScopes,$<scope>2);
        ASTNode_Block* b=new ASTNode_Block($3,$<scope>2,currScopes);
        $$=b;
    }
    ;

multi_stmt:
    {$$=new vector<ASTNode_Base*>();}
    | multi_stmt block_stmt {
        $1->push_back($2);
        $$=$1;
    }
    ;

multi_expr:
  SEPARATOR expr multi_expr { $3->push_back($2);$$=$3; }
  | { $$ = new vector<ASTNode_Base*>(); }
  ;
multi_decl:
  multi_decl SEPARATOR ID decl{
        checkRedefine($3);
        ASTNode_Val* a=vtable->add(new ASTNode_Val(string($3)));
        a->setScope(currScopes->back());
        $1->push_back(new ASTNode_Assignment(a,$4));
        $$=$1;
  }
  | ID decl {
    checkRedefine($1);
    ASTNode_Val* a=vtable->add(new ASTNode_Val(string($1)));
        a->setScope(currScopes->back());
        vector<ASTNode_Assignment*> *r=new vector<ASTNode_Assignment*>();
        r->push_back(new ASTNode_Assignment(a,$2));
        $$=r;
  }
  ;
decl:
  ASSIGN expr{ $$=$2; }
  | {$$=0; }
  ;


expr:
    expr COMPARE expr {$$=new ASTNode_Math($1,$3,string($2));}
  | expr AND expr {$$=new ASTNode_And($1,$3);}
  | NOT expr {$$=new ASTNode_Not($2);}
  | expr OR expr {$$=new ASTNode_Or($1,$3);}
  | SUB expr %prec UMINUS {$$=new ASTNode_Neg($2);}
  | OPENP expr CLOSEP {$$=$2;}
  | expr SUB expr {$$=new ASTNode_Math($1,$3,'-');}
  | expr ADD expr {$$=new ASTNode_Math($1,$3,'+');}
  | expr MULT expr {$$=new ASTNode_Math($1,$3,'*');}
  | expr DIV expr {$$=new ASTNode_Math($1,$3,'/');}
  | expr MOD expr {$$=new ASTNode_Math($1,$3,'%');}
    | expr CARET expr {
        $$=new ASTNode_Exponent($1, $3);
    }
  | ID COASSIGN expr {
    checkUnknown($1);
    ASTNode_Math *result = new ASTNode_Math(retrieve($1),$3,$2[0]);
    $$=new ASTNode_Assignment(retrieve($1),result);
  }
  | ID ASSIGN expr {checkUnknown($1);$$=new ASTNode_Assignment(retrieve($1),$3);}
  | ID {checkUnknown($1);$$=retrieve($1);}
  | STATIC_INT {
    $$=new ASTNode_Int($1);
  }
    | STATIC_CHAR {
        $$=new ASTNode_Char($1);
    }
    | STATIC_STRING {
        $$=new ASTNode_String($1);
    }
    | ID ARRAY_LEFT expr ARRAY_RIGHT {
        checkUnknown($1);
        $$=new ASTNode_ArrayItem(retrieve($1),$3);

    }
    | ID ARRAY_LEFT expr ARRAY_RIGHT ASSIGN expr {
       checkUnknown($1);
        $$=new ASTNode_ArrayAssignment(retrieve($1),$3,$6);
    }
    | ID ARRAY_LEFT expr ARRAY_RIGHT COASSIGN expr {
       checkUnknown($1);
        ASTNode_ArrayItem *v = new ASTNode_ArrayItem(retrieve($1),$3);
        ASTNode_Math *result = new ASTNode_Math(v,$6,$5[0]);
        $$=new ASTNode_ArrayAssignment(retrieve($1),$3,result);
    }
    | ID METHOD_OP ID OPENP function_args CLOSEP {
        checkUnknown($1);
        $$=new ASTNode_BuiltIn(retrieve($1),$3,$5);
    }
    | ID OPENP function_args CLOSEP {
       ASTNode_BuiltIn *result;
       if ( string($1)!="random" &&
            string($1)!="print_mem") {
            result=new ASTNode_BuiltIn($1,$3,currScopes,vtable,&functions);
        } else {
            result=new ASTNode_BuiltIn(0,$1,$3);
        }
        $$=result;
    }
  ;
function_args:
    function_args SEPARATOR expr {
        $1->push_back($3);
        $$=$1;
    }
    | expr {
        vector<ASTNode_Base*>* args=new vector<ASTNode_Base*>();
        args->push_back($1);
        $$=args;
    }
    | {$$= new vector<ASTNode_Base*>();}


%%
int main(int argc, char* argv[]) {
    currScopes->push_back(globalScope);
  int argument;
  bool interpreter=false,debug=false,memory=false;


  while((argument = getopt(argc, argv, "hidm")) != -1) {
    switch(argument) {
      case 'h': help(); break;
      case 'i': interpreter=true; yyparse();break;
      case 'd': debug=true; break;
      case 'm': memory=true;break;
      case '?': exit(EXIT_FAILURE); break;
    }
  }

  vector<string> files;
  for(; optind < argc; optind++) {
    files.push_back(argv[optind]);
  }

  if(argc <= 1 && !interpreter) {
    error("Format: ./tube-ic[flags] [filename]\nType 'tube-ic -h' for help.");
  } else if(!(yyin = fopen(files[0].c_str(), "r"))) {
    error("Error opening " + files[0]);
  } else if(files.size() == 2) {
    ofstream out,tmp;
    tmp.open("compiler.tmp");
    out.open(files[1].c_str());
    if (out.fail()) {
      error("Error opening outfile " + files[1]);
    }
    // this will redirect all output directed at cout to our output
    // file
    streambuf * old = cout.rdbuf(tmp.rdbuf());
    cout<<"StartProgram:"<<endl;
    yyparse();
	for (unsigned i=0;i<functions.size();i++) {
		if (!functions[i]->defined)
			yyerror("function '"+functions[i]->getName()+"' never fully defined!");
	}
    cout.rdbuf(old);
    old=cout.rdbuf(out.rdbuf());
    IcLineTable l("compiler.tmp",debug, memory);
    l.compile();
    cout.rdbuf(old);
    cout << "Parse Successful!" << endl;
    exit(EXIT_SUCCESS);
  } else {
    ofstream out;
    out.open("compiler.tmp");
    if (out.fail()) {
        error("Error creating temp files");
    }
    streambuf* old=cout.rdbuf(out.rdbuf());
    yyparse();
    cout.rdbuf(old);
    IcLineTable l("compiler.tmp",debug,memory);
    l.compile();
    //cout << "Parse Successful!" << endl;
    exit(EXIT_SUCCESS);
  }
}


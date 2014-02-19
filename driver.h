#ifndef TUBE_DRIVER
#define TUBE_DRIVER
#include "vtable.h"
#include "ast.h"
#include "lib.h"
#include <sys/stat.h>
#include <ctime>
#include <fstream>
using namespace std;
struct FOR_ARGS;
extern int yylex();
extern int yylineno;
extern int yyparse();
extern void yyerror(string s);
extern FILE* yyin;
void checkRedefine(string);
void checkUnknown(string);
void checkNull(string);
void error(string);
void deleteIfEmpty();
string findType(Addr*);
void help();

string outputFile;
/* Global Variables **/
Scope *globalScope = new Scope(getScopeID());
vector<Scope*> *currScopes=new vector<Scope*>();
vector<ASTNode_Function*> functions;

ValTable *vtable=new ValTable();
unsigned tmp_count=0;


string findType(Addr* a) {
      string aType;
      if(a->type == VINT) { aType = "int"; } else { aType = "char"; }
      if(a->d != 0) { aType = "array(" + aType + ")"; }

      return aType;
    }
void checkNull(string v) {
    checkUnknown(v);
    for (unsigned i=0;i<currScopes->size();i++) {
        if (vtable->find(v,(*currScopes)[i])) {
            ASTNode_Val* item=vtable->retrieve(v,(*currScopes)[i]);
            if (item->addr()->value_state==0 && item->addr()->d==0) {
                yyerror("uninitialized variable '" +string(v)+"'");
            }
        }
    }
}
void checkRedefine(string v) {
    for (unsigned i=0;i<currScopes->size();i++) {
	    if (vtable->find(v,currScopes->at(i)))
		    yyerror("re-defining variable '" + string(v)+"'");
    }
}

void checkUnknown(string v) {
    for (unsigned i=0;i<currScopes->size();i++) {
        if (vtable->find(v,(*currScopes)[i]))
            return;
    }
    yyerror("unknown variable '" + string(v)+"'");
}
void yyerror(string s) {
	cerr<< "ERROR(line " << yylineno << "): " << s << endl;
  deleteIfEmpty();
	exit(EXIT_FAILURE);
}
void deleteIfEmpty() {
  struct stat fileInformation;
  stat(outputFile.c_str(), &fileInformation);
  if(fileInformation.st_size == 0) {
    remove(outputFile.c_str());
  }
}
void error(string s) {
	cerr<<s<<endl;
	exit(EXIT_FAILURE);
}
ASTNode_Val* retrieve(string v) {
	checkUnknown(v);
    for (unsigned i=0;i<currScopes->size();i++) {
        if (vtable->find(v,(*currScopes)[i])) {
            return vtable->retrieve(v,(*currScopes)[i]);
        }
    }
    return nullptr;
}
void help() {
	cout << "Tubular Compiler v. 3.0" << endl;
	cout << "Format: tube-ic[flags] [filename]" << endl << endl;
	cout << "Flags:" << endl;
	cout << "  -h  :  Help (this information)" << endl;
	cout << "  -i  :  Interpret input code rather than compile" << endl;
	exit(EXIT_SUCCESS);
}
#endif

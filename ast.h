#ifndef AST_H_
#define AST_H_

#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <sstream>
#include <typeinfo>
#include "vtable.h"


class ASTNode_Block;
class ASTNode_Function;
class ASTNode_Multi_Assignment;
class ASTNode_Assignment;
class ASTNode_Loop;
class ASTNode_Math;
class ASTNode_Base;
struct Scope;
void removeScope(vector<Scope*>*,Scope*);
struct Addr;
extern int yylineno;

inline void removeScope(vector<Scope*>* s,Scope* _s) {
    vector<Scope*>::iterator i;
    for (i=s->end();i!=s->begin();i--) {
        if (*i==_s)
            break;
    }
    s->erase(i);
    return;
}
using namespace std;
enum SCOPE_TYPE {
    SGLOBAL,SNORMAL,SWHILE,SFOR
};
enum VAL_TYPE {
    VINT,VCHAR,VARRAY,VNULL
};
struct Ctype {
    VAL_TYPE t;
    unsigned d;
    Ctype() {}
    Ctype(VAL_TYPE a,unsigned b):t(a),d(b) {}
};
struct Addr {
	string value;
    VAL_TYPE type;
    bool value_state;
    unsigned d;
	bool constant;
	Addr(string v):value(v),d(0) {value_state=0;constant=false;}
    Addr& operator+(int v) {
        stringstream ss;
        ss<<value;
        int mem_addr;
        ss>>mem_addr;
        mem_addr+=v;
        ss<<mem_addr;
        Addr* a=new Addr(ss.str());
        a->type=type;
        a->value_state=value_state;
        a->d=d;
        return *a;
    }
};
struct Array_Type {
    VAL_TYPE type;
    unsigned d;
    Array_Type(string t) {
        if (t=="int") {
            type=VINT;
        } else if (t=="char") {
            type=VCHAR;
        }
        d=1;
    }
};
struct Scope {
    string id;
    ASTNode_Loop* assoc_loop;
    ASTNode_Function* assoc_func;
    SCOPE_TYPE type;
    Scope(string _id):id(_id),assoc_loop(0),assoc_func(0),type(SGLOBAL){}
    ~Scope() {}
};

class ASTNode_Base {
  protected:
	vector<ASTNode_Base*> args;
    void pop(Addr* a) {
        cout<<"pop "<<a->value<<endl;
    }
    void push(Addr* a) {
        cout<<"push "<<a->value<<endl;
    }
    void checkType(Addr* a,Addr* b) {
        if (a->type!=b->type) {
            string aType = findType(a);
            string bType = findType(b);
            string mismatch = "types do not match for assignment (lhs='"+aType+"', rhs='"+bType+"')";

            throw mismatch.c_str();
        }
    }
    // takes the two relationship expressions
    void checkRelType(Addr* a, Addr* b) {
      if(a->type != b->type || a->d != 0 || b->d != 0) {
            string aType = findType(a);
            string bType = findType(b);

            string mismatch = "types do not match for relationship operator (lhs='" + aType + "', rhs='" + bType + "')";
            throw mismatch.c_str();
      }
    }
    void checkMathType(Addr* a) {
      string aType = findType(a);

      if(a->type != VINT || a->d != 0) {
        string mismatch = "cannot use type '" + aType + "' in mathematical expressions";
        throw mismatch.c_str();
      }
    }

    string findType(Addr* a) {
      string aType;
      if(a->type == VINT) { aType = "int"; } else { aType = "char"; }
      if(a->d != 0) { aType = "array(" + aType + ")"; }

      return aType;
    }
  public:
	ASTNode_Base() {;}
	virtual ~ASTNode_Base() {
	    for (auto i=args.begin();i!=args.end();i++) {
			delete (*i);
		}
	}
	virtual Addr* toIC()=0;
};
class ASTNode_Dummy:public ASTNode_Base {
  public:
    ASTNode_Dummy(){}
    Addr* toIC() {return nullptr;}
};
class ASTNode_Block:public ASTNode_Base {
  private:
    vector<Scope*>* currS;
    Scope*  _scope;
    string _exit;
  public:
    ASTNode_Block(vector<ASTNode_Base*>* stmts,Scope* newS,vector<Scope*>* Scopes) {
       currS=Scopes;
        _scope=newS;
        for (unsigned i=0;i<stmts->size();i++) {
            args.push_back(stmts->at(i));
        }
    };
    Addr* toIC();
    string exit() {return _exit;}
    void setExit(string s) {_exit=s;}
    Scope* scope() {return _scope;}
};

struct ArrayIndex {
    ASTNode_Base* index;
    unsigned d;
    ArrayIndex(ASTNode_Base* _i):index(_i),d(1) {}
};

class ASTNode_Neg:public ASTNode_Base {
  public:
	ASTNode_Neg(ASTNode_Base * n) {
		args.push_back(n);
	}
	~ASTNode_Neg() {}
	Addr* toIC();
};

class ASTNode_Math: public ASTNode_Base {
  private:
    char _op;
    string _rop;
    bool relation;
  public:
	ASTNode_Math(ASTNode_Base* a,ASTNode_Base* b,char op):_op(op),relation(0){
		args.push_back(a);
		args.push_back(b);
	}
    ASTNode_Math(ASTNode_Base* a,ASTNode_Base* b,string op):_rop(op),relation(1) {
        args.push_back(a);
        args.push_back(b);
    }
	Addr* toIC();
};

class ASTNode_Exponent: public ASTNode_Base {
  public:
	ASTNode_Exponent(ASTNode_Base* a,ASTNode_Base* b) {
		args.push_back(a);
		args.push_back(b);
	}
	Addr* toIC();
};

class ASTNode_And: public ASTNode_Base {
  public:
    ASTNode_And(ASTNode_Base* a, ASTNode_Base* b) {
      args.push_back(a);
      args.push_back(b);
    }
    Addr* toIC();
};


class ASTNode_Not: public ASTNode_Base {
  public:
    ASTNode_Not(ASTNode_Base* a) {
      args.push_back(a);
    }
    Addr* toIC();
};

class ASTNode_Or: public ASTNode_Base {
  public:
    ASTNode_Or(ASTNode_Base* a, ASTNode_Base* b) {
      args.push_back(a);
      args.push_back(b);
    }
    Addr* toIC();
};

// BASIC TYPES!!!!!!!!!!!!!!!
class ASTNode_Val:public ASTNode_Base {
  protected:
	string _id;
	Addr *_addr;
    Scope *_scope;
  public:
	ASTNode_Val(string id):_id(id),_addr(0) {}
	void setAddr(Addr *a){_addr=a;}
	Addr* addr() {return _addr;}
    void setScope(Scope* s){_scope=s;}
    Scope* scope() {return _scope;}
	string id() {return _id;}
	~ASTNode_Val() {}
	virtual Addr* toIC();
};
class ASTNode_ArrayItem:public ASTNode_Base {
  protected:
    ASTNode_Val* target;
  public:
    ASTNode_ArrayItem(ASTNode_Val* ar,ASTNode_Base* expr) {
        target=ar;
        args.push_back(expr);
    }
    Addr* toIC();
};
/***
class ASTNode_Val_Int:public ASTNode_Val {

};
class ASTNode_Val_Char:public ASTNode_Val {

};
***/
class ASTNode_Int:public ASTNode_Base {
  private:
	int _v;
	Addr* a;
  public:
	ASTNode_Int(int v):_v(v) {
		a=new Addr(to_string(v));	
		a->constant=true;
		a->type=VINT;
	}
	Addr* toIC();
};
class ASTNode_Char:public ASTNode_Base {
  private:
    string _v;
	Addr* a;
  public:
    ASTNode_Char(string v):_v(v) {
		a=new Addr(v);
		a->constant=true;
		a->type=VCHAR;
	}
    Addr* toIC();
};
class ASTNode_String:public ASTNode_Base {
  private:
    string _v;
  public:
    ASTNode_String(string v):_v(v) {}
    Addr* toIC();
};

class ASTNode_Print:public ASTNode_Base {
  public:
    ASTNode_Print(vector<ASTNode_Base*> *v) {
        for (int i=v->size()-1;i>=0;i--) {
            args.push_back((*v)[i]);
        }
    }
    Addr* toIC();
};
class ASTNode_ArrayAssignment:public ASTNode_Base {
  private:
    ASTNode_Val* target;
  public:
    ASTNode_ArrayAssignment(ASTNode_Val* a,ASTNode_Base* index,ASTNode_Base* value) {
        target=a;
        args.push_back(index);
        args.push_back(value);
    }
    Addr* toIC();
};
class ASTNode_Assignment: public ASTNode_Base {
  private:
	ASTNode_Val* t;
	Addr* _target;
    Addr* _source;
  public:
	ASTNode_Assignment(ASTNode_Val* a,ASTNode_Base *b) {
		t=a;
		args.push_back(b);
        _source=0;
		_target=0;
	}
    ASTNode_Assignment(ASTNode_Val* a,Addr* b) {
        t=a;
        _source=b;
		_target=0;
    }
	ASTNode_Assignment(Addr* a,Addr* b) {
		t=0;
		_target=a;
		_source=b;
	}
    ASTNode_Val* val() {return t;}
    ASTNode_Base* source() {return args[0];}
	~ASTNode_Assignment() {}
	Addr* toIC();
};
class ASTNode_Multi_Assignment:public ASTNode_Base {
  private:
    vector<ASTNode_Assignment*> assigns;
  public:
    ASTNode_Multi_Assignment(vector<ASTNode_Assignment*> *a) {
          for (unsigned i=0;i<a->size();i++)
              assigns.push_back(a->at(i));
    }
    Addr* toIC() {
        for (unsigned i=0;i<assigns.size();i++)
            assigns[i]->toIC();
        return nullptr;
    }
};
class ASTNode_BuiltIn:public ASTNode_Base {
  private:
    string name;
    ASTNode_Function* func;
    vector<Scope*> *currScopes;
	vector<ASTNode_Base*> *pass_args;
	vector<ASTNode_Function*> *functions;
    ValTable* vtable;
  public:
    ASTNode_BuiltIn(ASTNode_Val* target,string func,vector<ASTNode_Base*>* p_args) {
        name=func;
        args.push_back(target);
		pass_args=p_args;
    }
    ASTNode_BuiltIn(string aaa,vector<ASTNode_Base*>* p_args,vector<Scope*> *c,ValTable* v,vector<ASTNode_Function*> *fs):currScopes(c),vtable(v) {
		func=0;
		name=aaa;
		functions=fs;
		pass_args=p_args;
    }
    Addr* toIC();
};
class ASTNode_If_Else:public ASTNode_Base {
  public:
    ASTNode_If_Else(ASTNode_Base* cond,ASTNode_Base* stmts,ASTNode_Base* elseStmts) {
        args.push_back(cond);
        args.push_back(stmts);
        args.push_back(elseStmts);
    }
    Addr* toIC();
};
class ASTNode_Loop:public ASTNode_Base {
  protected:
    string _exitLabel;
  public:
    ASTNode_Loop() {;}
    string exitLabel() {return _exitLabel;}
};
class ASTNode_While:public ASTNode_Loop {
  private:
    vector<Scope*>* _s;
    Scope* _scope;
  public:
    ASTNode_While(ASTNode_Base* cond,ASTNode_Base* b,vector<Scope*>* ss,Scope* s) {
        args.push_back(cond);
        args.push_back(b);
        _s=ss;
        _scope=s;
    }
    Addr* toIC();
};
class ASTNode_For:public ASTNode_Loop {
  private:
      Scope* _scope;
      vector<Scope*>* _s;
  public:
    ASTNode_For(ASTNode_Base* a,ASTNode_Base* b,ASTNode_Base* c,ASTNode_Base *d,vector<Scope*>* ss,Scope* s) {
        _scope=s;
        _s=ss;
        args.push_back(a);
        args.push_back(b);
        args.push_back(c);
        args.push_back(d);
    }
    Addr* toIC();
};
class ASTNode_Break:public ASTNode_Base {
  private:
    vector<Scope*>* currScopes;
  public:
    ASTNode_Break(vector<Scope*>* s):currScopes(s) {}
    Addr* toIC();
};
class ASTNode_Return:public ASTNode_Base {
private:
    vector<Scope*> *currScopes;
public:
    ASTNode_Return(ASTNode_Base* a,vector<Scope*> *c):currScopes(c) {
        args.push_back(a);
    }
    Addr* toIC();
};
class ASTNode_Function:public ASTNode_Base {
private:
    string _id;
    vector<ASTNode_Val*>* _Args;
    Addr* _addr;
    Scope* scope;
    vector<Scope*> *currScopes;
    string _exitLabel;
public:
    ASTNode_Function(string id,vector<ASTNode_Val*> *Args,Addr* addr,ASTNode_Base* a,Scope* s,vector<Scope*> *scopes):_id(id),_Args(Args),_addr(addr),scope(s),currScopes(scopes) {
        args.push_back(a);
		defined=0;
    }
	bool defined;
    Addr* addr() {return _addr;}
    vector<ASTNode_Val*>* Args(){
        if (_Args==0) {
            return new vector<ASTNode_Val*>();
        } else {
            return _Args;
        }
    }
    string getName() {return _id;}
    Scope* getScope() {return scope;}
	void setScope(Scope* s) {scope=s;}
    string exitLabel() {return _exitLabel;}
    void setArgs(vector<ASTNode_Val*>* a){_Args=a;}
    void setBlock(ASTNode_Base* b) {args[0]=b;}
    Addr* toIC();
};


#endif /*AST_H_*/

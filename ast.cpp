#include "ast.h"

Addr* ASTNode_Neg::toIC() {
    Addr *var=args[0]->toIC();
    Addr *s=new Addr(getID());
    s->type=VINT;
    checkType(var,s);
    cout<<"sub 0 "<<var->value<<" "<<s->value<<endl;
    return s;
}
Addr* ASTNode_Math::toIC() {
    Addr* var1 = args[1]->toIC();
    Addr* var0 = args[0]->toIC();
    Addr *s=new Addr(getID());
    s->type=VINT;
    if (!relation) {
        checkMathType(var0);
        checkMathType(var1);
        switch (_op) {
            case '+':
                cout<<"add ";break;
            case '-':
                cout<<"sub ";break;
            case '*':
                cout<<"mult ";break;
            case '/':
                cout<<"div ";break;
            case '%':
                cout<<"mod ";break;
        }
    } else {
        checkRelType(var0,var1);
        if (_rop=="==") {
            cout<<"test_equ ";
        } else if (_rop=="!=") {
            cout<<"test_nequ ";
        } else if (_rop=="<") {
            cout<<"test_less ";
        } else if (_rop==">") {
            cout<<"test_gtr ";
        } else if (_rop=="<=") {
            cout<<"test_lte ";
        } else if (_rop==">=") {
            cout<<"test_gte ";
        }
    }
    cout<<var0->value<<" "<<var1->value<<" "<<s->value<<endl;
    return s;
}

Addr* ASTNode_And::toIC() {
    Addr* var0 = args[0]->toIC();
    Addr* result = new Addr(getID());
    result->type = VINT;

    string l = getLabelID();

    cout << "val_copy 0 " << result->value << endl;
    cout << "jump_if_0 " << var0->value << " " << l << endl;
    Addr* var1 = args[1]->toIC();
    cout << "jump_if_0 " << var1->value << " " << l << endl;
    cout << "val_copy 1 " << result->value << endl;
    cout << l << ":" << endl;
    return result;
}
Addr* ASTNode_Or::toIC() {
    Addr* var0 = args[0]->toIC();
    Addr* result = new Addr(getID());
    result->type = VINT;
    string l = getLabelID();
    cout << "val_copy 1 " << result->value << endl;
    cout << "jump_if_n0 " << var0->value << " " << l << endl;
    Addr* var1 = args[1]->toIC();
    cout << "jump_if_n0 " << var1->value << " " << l << endl;
    cout << "val_copy 0 " << result->value << endl;
    cout << l << ":" << endl;
    return result;
}


Addr* ASTNode_Not::toIC() {
    Addr* var0 = args[0]->toIC();
    Addr* result = new Addr(getID());
    result->type = VINT;
    string l = getLabelID();
    cout << "val_copy 1 " << result->value << endl;
    cout << "jump_if_0 " << var0->value << " " << l << endl;
    cout << "val_copy 0 " << result->value << endl;
    cout << l << ":" << endl;
    return result;
}


Addr* ASTNode_Exponent::toIC() {
    Addr* var1 = args[1]->toIC();
    Addr* var0 = args[0]->toIC();
    Addr* var2 = new Addr(getID());
    var2->type=VINT;
    checkType(var0,var2);
    checkType(var1,var2);
    string s0=var0->value;
    string s1=var1->value;
    string s2=var2->value;
    string s3=getID();
    string s4=getID();

    string l0=getLabelID();
    string l1=getLabelID();
    string l2=getLabelID();
    string l3=getLabelID();
    string l4=getLabelID();

    cout<< "# Begin Exponent" << endl;
    cout<< "jump_if_0 "+s1+" "+l1 << endl;
    cout<< "test_less "+s1+" 0 "+s3 << endl;
    cout<< "jump_if_n0 "+s3+" "+l2 << endl;
    cout<< "val_copy "+s0+" "+s2 << endl;
    cout<< "val_copy "+s1+" "+s4 << endl;
    cout<< l0+":" << endl;
    cout<< "test_gtr "+s4+" 1 "+s3 << endl;
    cout<< "jump_if_0 "+s3+" "+l3 << endl;
    cout<< "mult "+s2+" "+s0+" "+s2 << endl;
    cout<< "sub "+s4+" 1 "+s4 << endl;
    cout<< "jump "+l0 << endl;
    cout<< l4+":" << endl;
    cout<< "out_char '\\n'" << endl;
    printMessage("ERROR: undefined operation");
    cout<< "out_char '\\n'" << endl;
    cout<< "jump EndProgram" << endl;
    cout<< l1+":" << endl;
    cout<< "jump_if_0 "+s0+" "+l4 << endl;
    cout<< "val_copy 1 "+s2 << endl;
    cout<< "jump "+l3 << endl;
    cout<< l2+":" << endl;
    cout<< "jump_if_0 "+s0+" "+l4 << endl;
    cout<< "val_copy 0 "+s2 << endl;
    cout<< l3+":" << endl;

    cout<< "# End exponent" << endl;
    return var2;
}



Addr* ASTNode_Print::toIC() {
    for (unsigned i=0;i<args.size();i++) {
        Addr* s=args[i]->toIC();
        if (s->d==0) {
            if (s->type==VINT) {
                cout<<"out_int "<<s->value<<endl;
            } else if (s->type==VCHAR) {
                cout<<"out_char "<<s->value<<endl;
            }
        } else {
            if (s->type==VINT) {
                string tmpIndex=getID();
                string l1=getLabelID();
                string l2=getLabelID();
                string limit=getID();
                string b=getID();
                cout<<"ar_get_siz "<<s->value<<" "<<limit<<endl;
                cout<<"val_copy 0 "<<tmpIndex<<endl;
                cout<<l2<<":"<<endl;
                cout<<"test_less "<<tmpIndex<<" "<<limit<<" "<<b<<endl;
                cout<<"jump_if_0 "<<b<<" "<<l1<<endl;
                cout<<"ar_get_idx "<<s->value<<" "<<tmpIndex<<" "<<b<<endl;
                cout<<"out_int "<<b<<endl;
                cout<<"add "<<tmpIndex<<" 1 "<<tmpIndex<<endl;
                cout<<"jump "<<l2<<endl;
                cout<<l1<<":"<<endl;
            } else if (s->type==VCHAR) {
                string tmpIndex=getID();
                string l1=getLabelID();
                string l2=getLabelID();
                string limit=getID();
                string b=getID();
                cout<<"ar_get_siz "<<s->value<<" "<<limit<<endl;
				cout<<"test_equ "<<limit<<" 0 "<<b<<endl;
				cout<<"jump_if_n0 "<<b<<" "<<l1<<endl;
                cout<<"val_copy 0 "<<tmpIndex<<endl;
                cout<<l2<<":"<<endl;
                cout<<"test_less "<<tmpIndex<<" "<<limit<<" "<<b<<endl;
                cout<<"jump_if_0 "<<b<<" "<<l1<<endl;
                cout<<"ar_get_idx "<<s->value<<" "<<tmpIndex<<" "<<b<<endl;
                cout<<"out_char "<<b<<endl;
                cout<<"add "<<tmpIndex<<" 1 "<<tmpIndex<<endl;
                cout<<"jump "<<l2<<endl;
                cout<<l1<<":"<<endl;
            }
        }
    }
    cout<<"out_char '\\n'"<<endl;
    return new Addr("");
}

Addr* ASTNode_ArrayItem::toIC() {
    Addr* result=new Addr(getID());
    result->type = target->addr()->type;
    Addr* index=args[0]->toIC();
    if (target->addr()->d==0) {
        string t;
        if (target->addr()->type==VINT)
            t="int";
        else if (target->addr()->type==VCHAR)
            t="char";
        string errmsg="Trying to index into non-array type '"+t+"'.";
        throw errmsg.c_str();
    }
    if (index->type != VINT) {
        throw "array indicies must be of type int";
    }
    cout<<"ar_get_idx "<<target->addr()->value<<" "<<index->value<<" "<<result->value<<endl;
    return result;
}
Addr* ASTNode_BuiltIn::toIC() {
    Addr* result=new Addr(getID());
    if (name=="random") {
        if (pass_args->size()!=1) {
            throw "random takes exactly 1 argument";
        }
        Addr* arg=pass_args->at(0)->toIC();
        if (arg->d!=0) {
            throw "argument cannot be an array";
        }
        if (arg->type!=VINT) {
            throw "argument must be integer";
        }
        cout<<"random "<<arg->value<<" "<<result->value<<endl;
        result->type=VINT;
        return result;
    } else if (name=="print_mem") {
        result->type=VINT;
        if (pass_args->size()!=0)
            throw "print_mem() does not take any arguments";
        cout<<"print_mem"<<endl;
        return result;
    } else if (name=="size") {
        Addr* target=args[0]->toIC();
        if (target->d==0) {
            throw "no such method";
        }
        if (pass_args->size()!=0) {
            throw "too much arguments";
        }
        result->type=VINT;
        cout<<"ar_get_siz "<<target->value<<" "<<result->value<<endl;
    } else if (name=="resize") {
        Addr* target=args[0]->toIC();
        if (target->d==0) {
            throw "no such method";
        }
        if (pass_args->size()!=1) {
            throw "too much arguments";
        }
        //cout<<"ar_set_siz "<<target->value<<" "<<pass_args[0]->value<<endl;
        cout<<"ar_resize "<<target->value<<" "<<pass_args->at(0)->toIC()->value<<endl;
        result=target;
    } else {
		vector<Addr*> as;
        vector<ASTNode_Val*> defined_args;
		bool matched=false;
		bool incorrectNumber=false;
		bool not_defined=false;
		for (unsigned i=0;i<pass_args->size();i++) {
			as.push_back(pass_args->at(i)->toIC());
		}
		for (unsigned i=0;i<functions->size();i++) {
			ASTNode_Function* _f = functions->at(i);
			vector<ASTNode_Val*> __args=*(_f->Args());
			if (_f->getName()!=name)
				continue;
			matched=true;
			if (__args.size()!=as.size()) {
				incorrectNumber=true;
				continue;
			}
			bool found=true;
			for (unsigned j=0;j<__args.size();j++) {
				if (as[j]->type!=__args[j]->addr()->type ||
					as[j]->d!=__args[j]->addr()->d) {
						found=false;
						break;
				}
			}
			if (found) {
				func=_f;
				defined_args=*(_f->Args());
			break;
			}
		}
		if (not_defined) {
			string msg="function  '"+name+"' declared but not defined";
			throw msg.c_str();
			return nullptr;

		}
		if (!matched) {
			string msg="unknown function '"+name+"'";
			throw msg.c_str();
			return nullptr;
		}
		if (incorrectNumber && func==0) {
			string msg="Incorrect number of arguments provided for function '"+name+"'";
			throw msg.c_str();
			return nullptr;
	
		}
		if (func==0) {
			string msg="Incorrect argument type provided for function '"+name+"'";
			throw msg.c_str();
			return nullptr;
		}
		if (func->addr()->d!=0) {
			result=new Addr(getArrayID());
			cout<<"ar_set_siz "<<result->value<<" 0"<<endl;
		} else {
			result=new Addr(getID());
		}
        //result=func->addr();
		result->d=func->addr()->d;
		result->type=func->addr()->type;
        vector<Scope*>::iterator func_iter=currScopes->end();
        for (auto i=currScopes->begin();i!=currScopes->end();i++) {
            if ((*i)->assoc_func!=0) {
                func_iter=i;
            }
        }
        vector<ASTNode_Val*> toBePushed;
        ASTNode_Val* result_val=new ASTNode_Val("result");
        result_val->setAddr(result);
        result_val->setScope(currScopes->back());
        vtable->add(result_val);
        if (func_iter!=currScopes->end()) {
            for (auto i=func_iter;i!=currScopes->end();i++) {
                vector<ASTNode_Val*> tmp=vtable->findAt(*i);
                toBePushed.insert(toBePushed.end(),tmp.begin(),tmp.end());
            }
            for (unsigned i=0;i<toBePushed.size();i++) {
				/*
				if (toBePushed[i]->addr()->d!=0) {
					continue;
				}
				*/
                push(toBePushed[i]->addr());
            }
        }
        for (unsigned i=0;i<pass_args->size();i++) {
			ASTNode_Assignment copy(defined_args[i]->addr(),as[i]);
			copy.toIC();
        }
        cout<<"call function_"<<func->getScope()->id<<func->getName()<<endl;
        if (func_iter!=currScopes->end()) {
            for (int i=toBePushed.size()-1;i>=0;i--) {
				/*
				if (toBePushed[i]->addr()->d!=0) {
					continue;
				}
				*/
                pop(toBePushed[i]->addr());
            }
        }
		ASTNode_Assignment copy(result,func->addr());
		copy.toIC();
    }
    return result;
}
Addr* ASTNode_ArrayAssignment::toIC() {
    Addr* index=args[0]->toIC();
    Addr* value=args[1]->toIC();
    if (index->type!=VINT||index->d!=0) {
        throw "array indicies must be of type int";
    }
    checkType(target->addr(),value);
    if (target->addr()->d==0) {
      string type;
      if(target->addr()->type == 0) type = "int";
      else type = "char";
      string message = "Trying to index into non-array type '" + type  + "'.";
        throw message.c_str();
    }
    if (value->d!=0) {
      string aType;
      if(target->addr()->type == VINT) { aType = "int"; } else { aType = "char"; }
      string bType = findType(value);

      string message = "types do not match for assignment (lhs='" + aType + "', rhs='" + bType + "')";
      throw message.c_str();
    }
    cout<<"ar_set_idx "<<target->addr()->value<<" "<<index->value<<" "<<value->value<<endl;
    return value;
}
Addr* ASTNode_Assignment::toIC() {
    Addr* source;
	Addr* target;
	if (_target==0) {
		target=t->addr();
	} else {
		target=_target;
	}
    if (_source==0) {
        source=args[0]->toIC();
    } else {
        source=_source;
    }
    checkType(target,source);
    if (source->d!=target->d) {
        string aType = findType(target);
        string bType = findType(source);
        string message = "types do not match for assignment (lhs='" + aType + "', rhs='" + bType + "')";
        throw message.c_str();
    }
    if (source->d==1 && target->d==1) {
        string tmpS=getID();
        cout<<"ar_get_siz "<<source->value<<" "<<tmpS<<endl;
        cout<<"ar_set_siz "<<target->value<<" "<<tmpS<<endl;
        string tmpIndex=getID();
        string l1=getLabelID();
        string l2=getLabelID();
        string tmpItem=getID();
        string tmpS2=getID();
        cout<<"val_copy 0 "<<tmpIndex<<endl;
        cout<<l2<<":"<<endl;
        cout<<"test_less "<<tmpIndex<<" "<<tmpS<<" "<<tmpS2<<endl;
        cout<<"jump_if_0 "<<tmpS2<<" "<<l1<<endl;
        cout<<"ar_get_idx "<<source->value<<" "<<tmpIndex<<" "<<tmpItem<<endl;
        cout<<"ar_set_idx "<<target->value<<" "<<tmpIndex<<" "<<tmpItem<<endl;
        cout<<"add "<<tmpIndex<<" 1 "<<tmpIndex<<endl;
        cout<<"jump "<<l2<<endl;
        cout<<l1<<":"<<endl;
    } else {
        cout<<"val_copy "<<source->value<<" "<<target->value<<endl;
    }
    return target;
}
Addr* ASTNode_Int::toIC() {
  return a;
}
Addr* ASTNode_Char::toIC() {
  return a;
}
Addr* ASTNode_String::toIC() {
    Addr* s=new Addr(getArrayID());
    s->type=VCHAR;
    s->d=1;
    unsigned number_escapes=0;
    for (unsigned i=1;i<_v.length()-1;i++) {
            if (_v[i] == '\\') {
                number_escapes++;
                i++;
            }
    }
    cout<<"ar_set_siz "<<s->value<<" "<<_v.length()-2-number_escapes<<endl;

    unsigned index_var=0;
    for (unsigned i=1;i<_v.length()-1;i++) {
        if (_v[i]=='\n') {
            cout<<"ar_set_idx "<<s->value<<" "<<index_var<<" '\\n'"<<endl;
        } else if (_v[i] != '\\') {
            cout<<"ar_set_idx "<<s->value<<" "<<index_var<<" '"<<_v[i]<<"'"<<endl;
        } else {
            i++;
            if (_v[i] == '"')
                    cout<<"ar_set_idx "<<s->value<<" "<<index_var<<" '"<<_v[i]<<"'"<<endl;
            else
                cout<<"ar_set_idx "<<s->value<<" "<<index_var<<" '\\"<<_v[i]<<"'"<<endl;
        }
        index_var++;
    }
    return s;
}
Addr* ASTNode_Val::toIC() {
  return _addr;
}
Addr* ASTNode_Block::toIC() {
    currS->push_back(_scope);
    for (unsigned i=0;i<args.size();i++) {
        args[i]->toIC();
    }
    removeScope(currS,_scope);
    return nullptr;
}
Addr* ASTNode_If_Else::toIC() {
    Addr* cond = args[0]->toIC();
    if (cond->type!=VINT || cond->d!=0)
        throw "condition for if statements must evaluate to type int";
    string elseIf=getLabelID();
    string endIf=getLabelID();
    cout<<"jump_if_0 "<<cond->value<<" "<<elseIf<<endl;
    if (args[1]!=0) {
       args[1]->toIC();
    }
    cout<<"jump "<<endIf<<endl;
    cout<<elseIf<<":"<<endl;
    if (args[2]!=0) {
       args[2]->toIC();
    }
    cout<<endIf<<":"<<endl;
    return nullptr;
}
Addr* ASTNode_While::toIC() {
    _scope->assoc_loop=this;
    _s->push_back(_scope);
    string loopStart=getLabelID();
    string loopEnd=getLabelID();
    _exitLabel=loopEnd;
    cout<<loopStart<<":"<<endl;
    Addr* cond=args[0]->toIC();
    if (cond->type!=VINT || cond->d!=0)
        throw "condition for while statements must evaluate to type int";
    cout<<"jump_if_0 "<<cond->value<<" "<<loopEnd<<endl;
    args[1]->toIC();
    cout<<"jump "<<loopStart<<endl;
    cout<<loopEnd<<":"<<endl;
    removeScope(_s,_scope);
    return nullptr;
}
Addr* ASTNode_For::toIC() {
    string loopStart=getLabelID();
    string loopEnd=getLabelID();
    _exitLabel=loopEnd;
    _scope->assoc_loop=this;
    _s->push_back(_scope);
    if (args[0]!=0)
        args[0]->toIC();
    cout<<loopStart<<":"<<endl;
    Addr* loopCont=0;
    if (args[1]!=0) {
        loopCont=args[1]->toIC();
        if (loopCont->type!=VINT)
            throw "need a integer as condition";
        cout<<"jump_if_0 "<<loopCont->value<<" "<<loopEnd<<endl;
    }
    if (args[3]!=0)
        args[3]->toIC();
    if (args[2]!=0)
        args[2]->toIC();
    cout<<"jump "<<loopStart<<endl;
    cout<<loopEnd<<":"<<endl;
    removeScope(_s,_scope);
    return nullptr;
}
Addr* ASTNode_Break::toIC() {
    ASTNode_Loop *b=0;
    for (unsigned j=currScopes->size()-1;j>0;j--)  {
        Scope* i=currScopes->at(j);
        if (i->assoc_loop!=0) {
                b=i->assoc_loop;
                cout<<"jump "<<b->exitLabel()<<endl;
                return nullptr;
        }
    }
    throw "'break' command used outside of any loop";
    return nullptr;
}
Addr* ASTNode_Function::toIC() {
	cout<<"#***********************#"<<endl;
    return _addr;
}
Addr* ASTNode_Return::toIC() {
    ASTNode_Function* f;
	string msg="'return' run outside of any function.";
	bool exe=false;
    for (unsigned j=currScopes->size()-1;j>0;j--) {
        Scope* i=currScopes->at(j);
        if (i->assoc_func!=0) {
            f=i->assoc_func;
            Addr* a=args[0]->toIC();
            if (a->type!=f->addr()->type||
                a->d!=f->addr()->d) {
                string aType = findType(a);
                string bType = findType(f->addr());
                cerr<<"ERROR(line "<<yylineno
                  <<"): incorrect return type for function '"<<f->getName()
                  <<"'.  Expected: '"<<bType<<"', but found '"<<aType<<"')"
                  <<endl;
                exit(EXIT_FAILURE);
            }
			ASTNode_Assignment copy(f->addr(),a);
			copy.toIC();
            cout<<"ret"<<endl;
			exe=true;
			break;
        }   
    }
	if (!exe) {
    	throw msg.c_str();
	}
    return nullptr;
}


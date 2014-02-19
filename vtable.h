#ifndef VTABLE_H_
#define VTABLE_H_

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class ASTNode_Val;
struct Scope;
class ValTable {
  private:
	vector<ASTNode_Val*> mem;
  public:
	ASTNode_Val* add(ASTNode_Val*);
	bool find(string,Scope*) const;
    vector<ASTNode_Val*> findAt(Scope*) const;
	ASTNode_Val* retrieve(string,Scope*);
	vector<ASTNode_Val*> data(){return mem;}
	ValTable() {}
	~ValTable();
};

#endif /*VTABLE_H_*/

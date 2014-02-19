#include "vtable.h"
#include "ast.h"

ValTable::~ValTable() {
	while(!mem.empty()) {
		delete mem.back();
		mem.pop_back();
	}
}
ASTNode_Val* ValTable::add(ASTNode_Val* v) {
	mem.push_back(v);
	return v;
}
bool ValTable::find(string id,Scope* s) const {
	for (auto i=mem.begin();i!=mem.end();i++) {
		if ((*i)->id()==id && (*i)->scope()==s)
			return 1;
	}
	return 0;
}
ASTNode_Val* ValTable::retrieve(string id,Scope* s) {
	for (auto i=mem.begin();i!=mem.end();i++) {
		if ((*i)->id()==id && (*i)->scope()==s) {
            return *i;
		}
	}
	return nullptr;
}
vector<ASTNode_Val*> ValTable::findAt(Scope* s) const {
    vector<ASTNode_Val*> result;
    for (auto i=mem.begin();i!=mem.end();i++) {
        if ((*i)->scope()==s) {
            result.push_back(*i);
        }
    }
    return result;
}

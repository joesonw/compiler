#ifndef TUBE_IC_LIB_H_
#define TUBE_IC_LIB_H_
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

inline string getID() {
	static int i=0;
	return "s"+to_string(i++);
}
inline string getArrayID() {
    static int i=0;
    return "a"+to_string(i++);
}
static int counter=0;
inline string getID(unsigned size) {
    static int i=0;
    string result = to_string(i);
    i+=size;
    return result;
}
inline string popReg() {
    string result="regA";
    switch(counter) {
        case 0: counter++;result="regA";break;
        case 1: counter++;result="regB";break;
        case 2: counter++;result="regC";break;
        case 3: counter++;result="regD";break;
        case 4: counter++;result="regE";break;
        case 5: counter++;result="regF";break;
        case 6: counter++;result="regG";break;
        case 7: counter++;result="regH";break;
    }
    return result;
}
inline void pushReg() {
    counter--;
}
inline string getLabelID() {
	static int i=0;
	return "Label"+to_string(i++);
}
inline string getScopeID() {
    static int i=0;
    return "Scope"+to_string(i++);
}

inline void printMessage(string message) {
	for (char& c : message) {
		cout<<"out_char '"<<c<<"'"<<endl;
	}
	cout<<"out_char '\\n'"<<endl;
}


#endif

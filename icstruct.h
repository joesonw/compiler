#ifndef ICSTRUCT_H_
#define ICSTRUCT_H_
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#define AVAILABLE_MEMORY 55535
#define ACTUAL_MEMORY  65535
using namespace std;
struct IcLine {
    string cmd;
    string arg0;
    string arg1;
    string arg2;
    friend ostream& operator<<(ostream& out,IcLine& self) {
        out<<self.cmd<<" "<<self.arg0<<" "<<self.arg1<<" "<<self.arg2;
        return out;
    }
};
/*reserving registers
         *regA --- arith registers +
         *regB
         *regC --- arith registers -
         *regD
         *regE
         *regF
         *regG --- array ptr stack start
         *regH --- array stack start
         */
class IcLineTable {
private:
    bool debug;
    bool memory;
    unsigned scalar_counter=0;
    unsigned array_counter=0;
    vector<IcLine*> lines;
    string getLabelID() {
        static int i=0;
        return "IC"+to_string(i++);
    }
    void call(string routine) {
        cout<<"val_copy IP regF"<<endl;
        cout<<"add regF 5 regF"<<endl;
        push("regF");
        cout<<"jump "<<routine<<endl;
    }
    void ret() {
        pop("regF");
        cout<<"val_copy regF IP"<<endl;
    }
    void push(string r) {
        cout<<"store "<<r<<" regG"<<endl;
        cout<<"add regG 1 regG"<<endl;
    }
    void storeIP() {
        pop("regB");
    }
    void restoreIP() {
        push("regB");
    }
    void pop(string r) {
        cout<<"sub regG 1 regG"<<endl;
        cout<<"load regG "<<r<<endl;
    }
    void printMessage(string msg) {
        for (auto i:msg) {
            cout<<"out_char '"<<i<<"'"<<endl;
        }
        cout<<"out_char '\\n'"<<endl;
    }
    void printMsg(string msg) {
        for (auto i:msg) {
            cout<<"out_char '"<<i<<"'"<<endl;
        }
    }
    void loadReg(string reg,string arg) {
        if (arg[0]=='s') {
            cout<<"load "<<scalarToMem(arg)<<" "<<reg<<endl;
        } else if (arg[0]=='a') {
            string a=to_string(arrayToMem(arg));
            cout<<"val_copy "<<to_string(scalar_counter)<<" "<<reg<<endl;
            cout<<"add "<<reg<<" "<<a<<" "<<reg<<endl;
            cout<<"load "<<reg<<" "<<reg<<endl;
        } else {
            cout<<"val_copy "<<arg<<" "<<reg<<endl;
        }
    }
    void storeReg(string reg,string arg) {
        cout<<"store "<<reg<<" "<<scalarToMem(arg)<<endl;
    }
    unsigned scalarToMem(string arg) {
        arg.erase(0,1);
        stringstream ss(arg);
        unsigned i;
        ss>>i;
        return i;
    }
    unsigned arrayToMem(string arg) {
        arg.erase(0,1);
        stringstream ss(arg);
        unsigned i;
        ss>>i;
        return i;
    }
    void translate(IcLine* i) {
        string cmd=i->cmd;
        string arg0=i->arg0;
        string arg1=i->arg1;
        string arg2=i->arg2;
        if (cmd=="val_copy") {
            loadReg("regA",arg0);
            storeReg("regA",arg1);
        } else if (cmd=="storeIP") {
            storeIP();
        } else if (cmd=="restoreIP") {
            restoreIP();
        } else if (cmd=="push") {
            int mem;
            if (arg0[0]=='s') {
                mem=scalarToMem(arg0);
                cout<<"load "<<mem<<" regA"<<endl;
                push("regA");
            } else {
                mem=arrayToMem(arg0)+scalar_counter;
                cout<<"val_copy "<<mem<<" regA"<<endl;
				call("push_array");
            }
        } else if (cmd=="pop") {
            int mem;
            if (arg0[0]=='s') {
                mem=scalarToMem(arg0);
                pop("regA");  
                cout<<"store regA "<<mem<<endl;
            } else {
                mem=arrayToMem(arg0)+scalar_counter;
                cout<<"val_copy "<<mem<<" regA"<<endl;
				call("pop_array");
            }
        } else if (cmd=="ret") {
            ret();
        } else if (cmd=="call") {
            call(arg0);
        } else if (cmd=="add") {
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            cout<<"add regA regB regC"<<endl;
            storeReg("regC",arg2);
        } else if (cmd=="sub") {
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            cout<<"sub regA regB regC"<<endl;
            storeReg("regC",arg2);
        } else if (cmd=="mult") {
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            cout<<"mult regA regB regC"<<endl;
            storeReg("regC",arg2);
        } else if (cmd=="div") {
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            cout<<"div regA regB regC"<<endl;
            storeReg("regC",arg2);
        } else if (cmd=="mod") {
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            cout<<"mod regA regB regC"<<endl;
            storeReg("regC",arg2);
        } else if (cmd=="out_int") {
            loadReg("regA",arg0);
            cout<<"out_int regA"<<endl;
        } else if (cmd=="out_char") {
            loadReg("regA",arg0);
            cout<<"out_char regA"<<endl;
        } else if (cmd=="test_less") {
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            cout<<"test_less regA regB regC"<<endl;
            storeReg("regC",arg2);
        } else if (cmd=="test_gtr") {
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            cout<<"test_gtr regA regB regC"<<endl;
            storeReg("regC",arg2);
        } else if (cmd=="test_equ") {
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            cout<<"test_equ regA regB regC"<<endl;
            storeReg("regC",arg2);
        } else if (cmd=="test_nequ") {
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            cout<<"test_nequ regA regB regC"<<endl;
            storeReg("regC",arg2);
        } else if (cmd=="test_gte") {
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            cout<<"test_gte regA regB regC"<<endl;
            storeReg("regC",arg2);
        } else if (cmd=="test_lte") {
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            cout<<"test_lte regA regB regC"<<endl;
            storeReg("regC",arg2);
        } else if (cmd=="jump") {
            cout<<"jump "<<arg0<<endl;
        } else if (cmd=="jump_if_0") {
            loadReg("regA",arg0);
            cout<<"jump_if_0 regA "<<arg1<<endl;
        } else if (cmd=="jump_if_n0") {
            loadReg("regA",arg0);
            cout<<"jump_if_n0 regA "<<arg1<<endl;
        } else if (cmd=="ar_get_idx") {
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            call("check_index_out_bounds");
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            //cout<<"load regA regA"<<endl;
            cout<<"add 1 regB regB"<<endl;
            cout<<"add regA regB regA"<<endl;
            cout<<"load regA regA"<<endl;
            storeReg("regA",arg2);
        } else if (cmd=="ar_set_siz") {
            cout<<"val_copy "<<scalarToMem(arg0)<<" regA"<<endl;
            cout<<"add "<<to_string(scalar_counter)<<" regA regA"<<endl;
            cout<<"store regH regA"<<endl;
            cout<<"val_copy regH regA"<<endl;
            loadReg("regB",arg1);
            cout<<"store regB regA"<<endl;
            cout<<"add 1 regB regB"<<endl;
            cout<<"add regB regH regH"<<endl;
        } else if (cmd=="ar_set_idx") {
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            call("check_index_out_bounds");
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            loadReg("regC",arg2);
            cout<<"add 1 regB regB"<<endl;
            cout<<"add regA regB regA"<<endl;
            cout<<"store regC regA"<<endl;
        } else if (cmd=="ar_get_siz") {
            loadReg("regA",arg0);
            cout<<"load regA regA"<<endl;
            storeReg("regA",arg1);
        } else if (cmd=="ar_resize") {
            loadReg("regA",arg0);
            loadReg("regB",arg1);
            cout<<"val_copy "<<to_string(arrayToMem(arg0)+scalar_counter)<<" regC"<<endl;
            call("array_resize");
        } else if (cmd=="random") {
            loadReg("regA",arg0);
            cout<<"random regA regA"<<endl;
            storeReg("regA",arg1);
        } else if (cmd=="print_mem") {
            call("print_mem_usage");
        } else if (cmd=="ret") {
            ret();
        } else {
            cout<<*i<<endl;
        }
    }
public:
    IcLineTable(string fileName,bool d,bool m) {
        memory=m;
        debug=d;
        ifstream in;
        in.open(fileName.c_str());
        string line;
        while(getline(in,line)) {
            size_t pos = line.find("' '");
            if (pos!=std::string::npos) {
                line.replace(pos,3,"'\\s'");
            }
            pos = line.find("'\t'");
            if (pos!=std::string::npos) {
                line.replace(pos,3,"'\\t'");
            }

            stringstream ss(line);
            IcLine *i=new IcLine();
            ss>>i->cmd>>i->arg0>>i->arg1>>i->arg2;
            if (i->arg0=="'\\s'") {
                i->arg0="' '";
            }
            if (i->arg1=="'\\s'") {
                i->arg1="' '";
            }
            if (i->arg2=="'\\s'") {
                i->arg2="' '";
            }
            lines.push_back(i);
        }
    }
    void compile() {
        /****
         *identify number of scalar variables and array variables
         */

        for (unsigned i=0;i<lines.size();i++){
            IcLine* j=lines[i];
            if (j->arg0[0]=='s') {
                string tmp=j->arg0;
                unsigned n=scalarToMem(tmp);
                scalar_counter=max(scalar_counter,n+1);
            }
            if (j->arg1[0]=='s') {
                string tmp=j->arg1;
                unsigned n=scalarToMem(tmp);
                scalar_counter=max(scalar_counter,n+1);
            }
            if (j->arg2[0]=='s') {
                string tmp=j->arg2;
                unsigned n=scalarToMem(tmp);
                scalar_counter=max(scalar_counter,n+1);
            }
            if (j->arg0[0]=='a') {
                string tmp=j->arg0;
                unsigned n=scalarToMem(tmp);
                array_counter=max(array_counter,n+1);
            }
            if (j->arg1[0]=='a') {
                string tmp=j->arg1;
                unsigned n=scalarToMem(tmp);
                array_counter=max(array_counter,n+1);
            }
            if (j->arg2[0]=='a') {
                string tmp=j->arg2;
                unsigned n=scalarToMem(tmp);
                array_counter=max(array_counter,n+1);
            }
        }
        /**
         *allocating memories
        **/
        /*reserving registers
         *regA --- arith registers +
         *regB
         *regC --- arith registers -
         *regD
         *regE
         *regF
         *regG --- array ptr stack start
         *regH --- array stack start
         */


        /**
         * translate
         */
        cout<<"val_copy 55535 regG"<<endl;
        cout<<"val_copy "<<to_string(scalar_counter+array_counter)<<" regH"<<endl;
        cout<<"jump start"<<endl;
        cout<<"##system predefined routines"<<endl;
        //check_out_of_bounds_routine
        /* regA address to array in free memory sapce
         * regB index to be checked
         */
        cout<<"##CHECK_INDEX_OUT_BOUNDS()"<<endl;
        cout<<"check_index_out_bounds:"<<endl;
        if (debug) {
            cout<<"test_less regB 0 regC"<<endl;
            cout<<"jump_if_n0 regC OUT_BOUNDS_ERROR"<<endl;
            cout<<"load regA regA"<<endl;
            cout<<"test_gte regB regA regC"<<endl;
            cout<<"jump_if_n0 regC OUT_BOUNDS_ERROR"<<endl;
        }
        ret();
        cout<<"##ARRAY_RESIZE()"<<endl;
        cout<<"array_resize:"<<endl;
        /* regA address to array in free memory space
         * regB size of new array
         * regC address to array in array LUT
         */
        cout<<"load regA regD"<<endl;
        cout<<"test_gtr regB regD regE"<<endl;
        cout<<"jump_if_n0 regE array_move"<<endl;
        cout<<"store regB regA"<<endl;
        cout<<"jump end_array_resize"<<endl;
        cout<<"array_move:"<<endl;
        cout<<"add regH regB regF"<<endl;
        cout<<"test_lte regF "<<to_string(AVAILABLE_MEMORY)<<" regE"<<endl;
        cout<<"jump_if_0 regE ARRAY_RESIZE_ERROR"<<endl;
        cout<<"store regB regH"<<endl;
        cout<<"store regH regC"<<endl;
        cout<<"val_copy regH regF"<<endl;
        cout<<"add regH regB regH"<<endl;
        cout<<"add regH 1 regH"<<endl;
        cout<<"array_resize_loop:"<<endl;
        cout<<"sub regD 1 regD"<<endl;
        cout<<"test_gte regD 0 regE"<<endl;
        cout<<"jump_if_0 regE end_array_resize"<<endl;
        cout<<"add 1 regA regA"<<endl;
        cout<<"add 1 regF regF"<<endl;
        cout<<"mem_copy regA regF"<<endl;
        cout<<"jump array_resize_loop"<<endl;
        cout<<"end_array_resize:"<<endl;
        ret();

		cout<<"#PUSH_ARRAY"<<endl;
		cout<<"push_array:"<<endl;
		pop("regF");
		cout<<"load regA regB"<<endl;
		cout<<"load regB regC"<<endl;
		cout<<"test_gtr regC 0 regD"<<endl;
		cout<<"jump_if_0 regD push_array_1"<<endl;
		printMessage("non-0");
		cout<<"val_copy regB regE"<<endl;
		cout<<"add regE regC regE"<<endl;
		cout<<"push_array_0:"<<endl;
		cout<<"load regE regD"<<endl;
		push("regD");
		cout<<"out_int regE"<<endl;
		cout<<"out_char '\\n'"<<endl;
		cout<<"sub regE 1 regE"<<endl;
		cout<<"test_gtr regE regB regD"<<endl;
		cout<<"jump_if_n0 regD push_array_0"<<endl;
		cout<<"push_array_1:"<<endl;
		push("regC");
		push("regB");
		push("regF");
		ret();
		cout<<"#POP_ARRAY"<<endl;
		cout<<"pop_array:"<<endl;
		pop("regF");
		pop("regB");
		cout<<"store regB regA"<<endl;
		pop("regC");
		cout<<"store regC regB"<<endl;
		cout<<"pop_array_1:"<<endl;
		cout<<"test_gtr regC 0 regD"<<endl;
		cout<<"jump_if_0 regD pop_array_0"<<endl;
		cout<<"add regB 1 regB"<<endl;
		cout<<"sub regC 1 regC"<<endl;
		pop("regD");
		cout<<"store regD regB"<<endl;
		cout<<"jump pop_array_1"<<endl;
		cout<<"pop_array_0:"<<endl;
		push("regF");
		ret();
        if (debug) {
            cout<<"#PRINT_MEM_USAGE"<<endl;
            cout<<"print_mem_usage:"<<endl;
            printMsg("Total Memory Usage:");
            cout<<"val_copy 1 regA"<<endl;
            cout<<"add regA regH regA"<<endl;
            cout<<"out_int regA"<<endl;
            cout<<"out_char '\\n'"<<endl;
            printMessage("#  value");
            cout<<"val_copy 0 regB"<<endl;
            printMessage("scalar variables:");
            cout<<"mem_debug0:"<<endl;
            cout<<"load regB regC"<<endl;
            cout<<"out_int regB"<<endl;
            cout<<"out_char ' '"<<endl;
            cout<<"out_char ' '"<<endl;
            cout<<"out_int regC"<<endl;
            cout<<"out_char '\\n'"<<endl;
            cout<<"add 1 regB regB"<<endl;
            cout<<"test_less regB "<<scalar_counter<<" regA"<<endl;
            cout<<"jump_if_n0 regA mem_debug0"<<endl;
            printMessage("array variables:");
            cout<<"val_copy "<<scalar_counter<<" regB"<<endl;
            cout<<"mem_debug1:"<<endl;
            cout<<"load regB regC"<<endl;
            cout<<"out_int regB"<<endl;
            cout<<"out_char ' '"<<endl;
            cout<<"out_char ' '"<<endl;
            cout<<"out_int regC"<<endl;
            cout<<"out_char '\\n'"<<endl;
            cout<<"add 1 regB regB"<<endl;
            cout<<"test_less regB "<<(scalar_counter+array_counter)<<" regA"<<endl;
            cout<<"jump_if_n0 regA mem_debug1"<<endl;
            printMessage("free memory space:");
            cout<<"val_copy "<<(scalar_counter+array_counter)<<" regB"<<endl;
            cout<<"mem_debug2:"<<endl;
            cout<<"load regB regC"<<endl;
            cout<<"out_int regB"<<endl;
            cout<<"out_char ' '"<<endl;
            cout<<"out_char ' '"<<endl;
            cout<<"out_int regC"<<endl;
            cout<<"out_char '\\n'"<<endl;
            cout<<"add 1 regB regB"<<endl;
            cout<<"test_less regB regH regA"<<endl;
            cout<<"jump_if_n0 regA mem_debug2"<<endl;
            cout<<"out_char '\\n'"<<endl;
            ret();
        }

        cout<<"start:"<<endl;
        for (unsigned i=0;i<lines.size();i++) {
            cout<<"###"<<*lines[i]<<endl;
            translate(lines[i]);
        }
		cout<<"jump EndProgram"<<endl;
        cout<<"ARRAY_RESIZE_ERROR:"<<endl;
        if (debug) {
            printMessage("RUNTIME ERROR: insuffcient memory");
        }
        if (debug) {
            cout<<"jump EndProgram"<<endl;
            cout<<"OUT_BOUNDS_ERROR:"<<endl;
            printMessage("RUNTIME ERROR: index out-of-bounds");
        }
        cout<<"jump EndProgram"<<endl;
        cout<<"EndProgram:"<<endl;
        if (memory) {
            printMessage("");
            call("print_mem_usage");
        }
    }
};




#endif

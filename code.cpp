
#include<bits/stdc++.h>
#include<stdlib.h>
#include<fstream>
#include "R.h"
using namespace std;
//R format
vector<string>Rf;
//I format

int main()
{
    //Opening the assembly file
    ifstream file("asembly_code.asm");
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return 0;
    }
    //Taking every line of assembly code as strings in vector
    vector<string>lines;
    string s;
    while (getline(file, s)) {
        lines.push_back(s);
    }
    //Completed taking file as input
    file.close();
    //Adding R format instructions
    Rf.push_back("add");
    Rf.push_back("and");
    Rf.push_back("or");
    Rf.push_back("sll");
    Rf.push_back("slt");
    Rf.push_back("sra");
    Rf.push_back("srl");
    Rf.push_back("sub");
    Rf.push_back("xor");
    Rf.push_back("mul");
    Rf.push_back("div");
    Rf.push_back("rem");
    
    int flag=0;
    for(int i=0;i<lines.size();i++)
    {
        string ans="";
        string opcode="";
        int j=0;
        //Getting the opcode until space and avoiding space in from of the opcode
        while(lines[i][j]!=' ' || opcode=="")
        {
            //Checking if the instruction is comment or not
            if(lines[i][j]=='#')
            {
                flag++;
                break;
            }
            opcode=opcode+lines[i][j];
            j++;
            
        }
        
        //If its a comment
        if(flag)
        {
            flag=0;
            continue;
        }
        //If not a comment then proceeding with instruction
        for(int k=0;k<Rf.size();k++)
        {
            if(opcode==Rf[k])
            {
                ans=R(lines[i],j,opcode);
                break;
            }
        }
        

    }
    


}

#include<bits/stdc++.h>
#include<stdlib.h>
#include<fstream>
#include "R.h"
#include "I.h"
#include "S.h"
using namespace std;
//R format
vector<string>Rf;
//I format
vector<string>If;
//S format
vector<string>Sf;

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
    //Adding I format Instruction
    If.push_back("addi");
    If.push_back("andi");
    If.push_back("ori");
    If.push_back("lb");
    If.push_back("ld");
    If.push_back("lh");
    If.push_back("lw");
    If.push_back("jalr");
    //Adding S format
    Sf.push_back("sb");
    Sf.push_back("sw");
    Sf.push_back("sd");
    Sf.push_back("sh");
    //Addig Sb format
    //adding U format


    
    int flag=0;
    for(int i=0;i<lines.size();i++)
    {
        string ans="";
        string Mnemonic="";
        int j=0;
        //Getting the opcode until space and avoiding space in from of the opcode
        while(lines[i][j]!=' ' || Mnemonic=="")
        {
            //Checking if the instruction is comment or not
            if(lines[i][j]=='#')
            {
                flag++;
                break;
            }
            Mnemonic=Mnemonic+lines[i][j];
            j++;
            
        }
        
        //If its a comment
        if(flag)
        {
            flag=0;
            continue;
        }
        //If not a comment then proceeding with instruction
        //Checking if its R_format Mnemonics
        
        for(int k=0;k<Rf.size();k++)
        {
            if(Mnemonic==Rf[k])
            {
                ans=R(lines[i],j,Mnemonic);
                break;
            }
        }
        cout<<ans<<"\n";
        //Checking if its I format Mnemonic
        if(ans=="")
        {
            for(int k=0;k<If.size();k++)
            {
                if(Mnemonic==If[k])
                {
                    ans=I(lines[i],j,Mnemonic);
                    break;
                }
            
            }
            cout<<ans<<"\n";
            
 
        }
        //Checking if its S format Mnemonic
        if(ans=="")
        {
            for(int k=0;k<Sf.size();k++)
            {
                if(Mnemonic==Sf[k])
                {
                    ans=S(lines[i],j,Mnemonic);
                    break;
                }
            
            }
            cout<<ans<<"\n";

        }
        //Next time I will do S Mnemonics
        

    }
    


}

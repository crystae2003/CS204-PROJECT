#ifndef U_H
#define U_H
#include<bits/stdc++.h>
#include<string>
#include "R.h"
#include "I.h"
using namespace std;
string U(string s,int j,string Mnemonic)
{
    string ans="";
    string rd="";
    string imm="";
    int flag=0;
    //Extracting rd,imm fields
    if(Mnemonic=="auipc" || Mnemonic=="lui")
    {
        for(int i=j;i<s.size();i++)
        {
           if(s[i]=='x')
           {
              i++;
               if(flag==0)
                {
                  while(s[i]!=',' && s[i]!=' ')
                  {
                      rd=rd+s[i];
                      i++;
                  }
                  flag++;
                }
           }
           if(flag==1)
           {
               i++;
               while(i!=s.size() && s[i]!=' ')
                {
                    imm=imm+s[i];
                    i++;
                }
                flag=0;
                break;
           }
      }
    }
        
    //Adding opcode
    if(Mnemonic=="auipc")
    ans=ans+"0010111";
    else ans+="0110111";
    //Adding rd
    int rd_num=stoi(rd);
    ans=dectobin(rd_num,5)+ans;
    //Adding immediate
    int imm_num=stoi(imm);
    ans=dectobin(imm_num,20)+ans;
    //converting binary to hexa
    string hex=bintodec(ans);
    //returning in hexadecimal
    return hex;
}
#endif

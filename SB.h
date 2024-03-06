
#ifndef SB_H
#define SB_H
#include "R.h"
#include "I.h"
#include<bits/stdc++.h>
#include<string>
#include<unordered_map>
using namespace std;
string dtb(int n,int sign){
    string bin="";
    while(n!=0)
    {
        char c=char((n%2)+48);
         bin=c+bin;
         n=n/2;
    }
    while(bin.size()!=21)
    {
        if(sign==-1)
        bin='1'+bin;
        else
        bin='0'+bin;
    }
    return bin;

}
string fu3(string Mnemonic)
{
    if(Mnemonic=="beq")
    return "000";
    else if(Mnemonic=="bne")
    return "001";
    else if(Mnemonic=="blt")
    return "100";
    else
    return "101";

}
string SB(string s,int j,string Mnemonic,unordered_map<string,int>m_label,int PC)
{
    string rs1="";
    string rs2="";
    string label="";
    int flag=0;
    string ans="";
    for(int i=j;i<s.size();i++)
    {
        if(s[i]=='x')
        {
            i++;
            if(flag==0)
            {
                while(s[i]!=',' && s[i]!=' ')
                {
                    rs1=rs1+s[i];
                    i++;
                }
                flag++;
            }
            else if(flag==1)
            {
                while((s[i]!=',' && s[i]!=' ') ||rs2=="")
                {
                    rs2=rs2+s[i];
                    i++; 
                }
                flag++;
            }
        }
        if(flag==2)
        {
            i++;
            while(i!=s.size() && s[i]!=' ')
            {
                label=label+s[i];
                i++;
            }
            flag=0;
            break;
        }
      }
      int pc_2=m_label[label];
      int offset=pc_2-PC;
      //Adding opcode
      ans=ans+"1100011";
      //Adding immediate
      string imm;
      if(offset<0)
      imm=dtb(abs(offset),-1);
      else
      imm=dtb(offset,1);
      char eleven=imm[9];
      ans=eleven+ans;
      string huu=imm.substr(16,4);
      ans=huu+ans;
      //Adding func3
      huu=fu3(Mnemonic);
      ans=huu+ans;
      //Adding rs1
      int rs1_num=stoi(rs1);
      ans=dectobin(rs1_num)+ans;
      //Adding rs2
      int rs2_num=stoi(rs2);
      ans=dectobin(rs2_num)+ans;
      //Adding remaining immediate
      huu=imm.substr(10,6);
      ans=huu+ans;
      char twelve=imm[8];
      ans=twelve+ans;
      //converting binary to hexa
      string hex=bintodec(ans);
      //returning in hexadecimal
      return hex;
}
#endif

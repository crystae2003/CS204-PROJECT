#ifndef I_H
#define I_H
#include<bits/stdc++.h>
#include<string>
#include "R.h"
using namespace std;
string dectobin(int n,int size){
    string bin="";
    while(n!=0)
    {
        char c=char((n%2)+48);
         bin=c+bin;
         n=n/2;
    }
    while(bin.size()!=size)
    {
        bin='0'+bin;
    }
    return bin;

}
string func3I(string Mnemonic)
{
    if(Mnemonic=="lb" || Mnemonic=="jalr" || Mnemonic=="addi")
    return "000";
    else if(Mnemonic=="lh")
    return "001";
    else if(Mnemonic=="lw")
    return "010";
    else if(Mnemonic=="ld")
    return "011";
    else if(Mnemonic=="andi")
    return "111";
    else
    return "110";
}

string I(string s,int j,string Mnemonic)
{
    string ans="";
    string rd="";
    string rs1="";
    string imm="";
    int flag=0;
    //Extracting rd,rs1,imm fields
    if(Mnemonic=="addi" || Mnemonic=="andi" || Mnemonic=="ori")
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
                else if(flag==1)
               {
                  while((s[i]!=',' && s[i]!=' ') ||rs1=="")
                  {
                      rs1=rs1+s[i];
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
                    imm=imm+s[i];
                    i++;
                }
                flag=0;
                break;
           }
      }
    }
    else
    {
        for(int i=j;i<s.size();i++)
        {
            if(s[i]=='x' && flag==0)
           {
              i++;
               
                  while(s[i]!=',' && s[i]!=' ')
                  {
                      rd=rd+s[i];
                      i++;
                  }
                  flag++;
                
           }
           else if(flag==1 && s[i]!=' ')
           {
              while(s[i]!='(')
              {
                  imm=s[i]+imm;
                  i++;
              }
              flag++;
           }
           else if(flag==2 && s[i]!=' ')
           {
               if(s[i]=='x')
               {
                  i++;
                  while(s[i]!=')' && s[i]!=' ')
                  {
                      rs1=rs1+s[i];
                      i++;
                  }
                  break;

               }
           }

        }
        
    }
    //Adding opcode
    if(Mnemonic=="andi" || Mnemonic=="ori" || Mnemonic=="addi")
    ans=ans+"0010011";
    else if(Mnemonic=="jalr")
    ans+="1100111";
    else
    ans+="0000011";
    //Adding rd
    int rd_num=stoi(rd);
    ans=dectobin(rd_num,5)+ans;
    //Adding func3
    string func33=func3I(Mnemonic);
    ans=func33+ans;
    //Adding rs1
    int rs1_num=stoi(rs1);
    ans=dectobin(rs1_num,5)+ans;
    //Adding immediate
    int imm_num=stoi(imm);
    ans=dectobin(imm_num,12)+ans;
    //converting binary to hexa
    string hex=bintodec(ans);
    //returning in hexadecimal
    return hex;
}
#endif


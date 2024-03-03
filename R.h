#ifndef R_H
#define R_H
#include<bits/stdc++.h>
#include<string>
using namespace std;
string dectobin(int n){
    string bin="";
    while(n!=0)
    {
         bin=bin+char(n%2);
         n=n/2;
    }
    return bin;

}
string R(string s,int j,string opcode)
{
      string rd="";
      string rs1="";
      string rs2="";
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
            else if(flag==2)
            {
                while(i!=s.size() && s[i]!=' ')
                {
                    rs2=rs2+s[i];
                    i++;
                }
                flag=0;
                break;

            }
         }
         
      }
      ans=ans+"0110011";
      ans=""+ans;
      cout<<dectobin(5)<<"b\n";
      if(opcode=="add")
      {

      }
      
      
      return ans;
}
#endif

#ifndef SB_H
#define SB_H

#include <bits/stdc++.h>
#include <string>
#include "I.h"
#include "R.h"

using namespace std;

string funn3(string Mnemonic)
{
    if (Mnemonic == "beq") // SB format instruction
        return "000";
    else if (Mnemonic == "bne") // SB format instruction
        return "001";
    else if (Mnemonic == "blt") // SB format instruction
        return "100";
    else if (Mnemonic == "bge") // SB format instruction
        return "101";
    else if (Mnemonic == "bltu")
        return "110";
    else if (Mnemonic == "bgeu")
        return "111";
    else
        return "000"; // Default case
}

string S(string s, int j, string Mnemonic)
{
    string rs1 = "";
    string rs2 = "";
    string imm = "";
    string ans = "";
    int flag = 0;

    for (int i = j; i < s.size(); i++)
    {
        if (s[i] == 'x' && flag == 0)
        {
            i++;
            while (s[i] != ',' && s[i] != ' ')
            {
                rs1 += s[i];
                i++;
            }
            flag++;
        }
        else if (flag == 1 && s[i] != ' ')
        {
            while (s[i] != ',')
            {
                imm += s[i];
                i++;
            }
            flag++;
        }
        else if (flag == 2 && s[i] != ' ')
        {
            if (s[i] == 'x')
            {
                i++;
                while (s[i] != ')' && s[i] != ' ')
                {
                    rs2 += s[i];
                    i++;
                }
                break;
            }
        }
    }

    // Adding opcode
    ans = ans + "1100011";

    // Adding imm[12]
    if (imm[0] == '-')
    {
        ans += "1";
        imm.erase(0, 1); // Remove the negative sign
    }
    else
    {
        ans += "0";
    }

    // Adding imm[10:5]
    int imm_num = stoi(imm);
    string imm_complete = dectobin(imm_num, 12);
    string imm_part = imm_complete.substr(0, 7);
    ans = imm_part + ans;

    // Adding func3
    string fun3 = funn3(Mnemonic);
    ans = fun3 + ans;

    // Adding rs1
    int rs1_num = stoi(rs1);
    ans = dectobin(rs1_num, 5) + ans;

    // Adding rs2
    int rs2_num = stoi(rs2);
    ans = dectobin(rs2_num, 5) + ans;

    // Adding imm[4:1] and imm[11]
    string imm_part2 = imm_complete.substr(7, 4);
    string imm_part3 = imm_complete.substr(11, 1);
    ans = imm_part2 + imm_part3 + ans;

    // Converting binary to hexadecimal
    string hex = bintodec(ans);

    // Returning in hexadecimal
    return hex;
}

#endif // SB_H

#ifndef UJ_H
#define UJ_H

#include <bits/stdc++.h>
#include <string>
#include "I.h"
#include "R.h"

using namespace std;

string funn3(string Mnemonic)
{
    if (Mnemonic == "jal") // UJ format instruction
        return "110";
    else
        return "000"; // Default case
}

string UJ(string s, int j, string Mnemonic)
{
    string rd = "";  // Destination register
    string imm = ""; // Immediate value
    string ans = ""; // Resultant machine code

    for (int i = j; i < s.size(); i++)
    {
        if (s[i] == 'x')
        {
            i++;
            while (s[i] != ' ' && s[i] != ',' && s[i] != '(')
            {
                rd += s[i];
                i++;
            }
        }
        else if (s[i] == '-')
        { // Handling negative immediate values
            imm += s[i];
        }
        else if (isdigit(s[i]))
        {
            imm += s[i];
        }
    }

    // Adding opcode
    ans += "1101111";

    // Adding imm[20]
    if (imm[0] == '-')
    {
        ans += "1";
        imm.erase(0, 1); // Remove the negative sign
    }
    else
    {
        ans += "0";
    }

    // Adding imm[10:1]
    int imm_num = stoi(imm);
    string imm_complete = dectobin(imm_num, 21);
    string imm_part = imm_complete.substr(0, 10);
    ans += imm_part;

    // Adding imm[11]
    ans += imm_complete[10];

    // Adding imm[19:12]
    ans += imm_complete.substr(11, 8);

    // Adding rd
    int rd_num = stoi(rd);
    ans += dectobin(rd_num, 5);

    // Converting binary to hexadecimal
    string hex = bintodec(ans);

    // Returning in hexadecimal
    return hex;
}

#endif

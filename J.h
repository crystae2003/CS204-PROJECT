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

bool isValidLabel(const string &s)
{
    // Check if the string contains at least one character
    if (s.empty())
        return false;

    // Check if the first character is alphabetic
    if (!isalpha(s[0]))
        return false;

    // Check if all characters except the last one are alphanumeric or underscore
    for (size_t i = 1; i < s.size() - 1; ++i)
    {
        if (!isalnum(s[i]) && s[i] != '_')
            return false;
    }

    // Check if the last character is a colon
    return s.back() == ':';
}

string UJ(string s, int j, string Mnemonic, unordered_map<string, int> &labelAddresses)
{
    string rd = "";    // Destination register
    string label = ""; // Label
    string ans = "";   // Resultant machine code

    // Extracting destination register and label
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
        else if (isalpha(s[i]) || s[i] == '_')
        { // Detecting label
            while (isalnum(s[i]) || s[i] == '_')
            {
                label += s[i];
                i++;
            }
            // Check if the last character is a colon
            if (s[i] == ':')
            {
                if (isValidLabel(label))
                {
                    // Resolve label to its address
                    int targetAddress = labelAddresses[label];
                    // Calculate offset
                    int currentAddress = // calculate current address
                        int offset = targetAddress - currentAddress;
                    // Set immediate value
                    string imm = to_string(offset);
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
                else
                {
                    // Invalid label format
                    // Handle error or throw exception
                }
            }
        }
    }
}

#endif // UJ_H

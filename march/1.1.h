#pragma once
#include<iostream>
#include<string>

bool Is_Word(std::string b) {
    if (b == "NOT" || b == "AND" || b == "TRUE" || b == "FALSE") return true;
    return false;
}
std::string Logical_Expression(const std::string& a, int l) {
    std::string ans;
    for (int i = 0; i < l; ++i)
    {
        if (a[i] == '(')
        {
            ans.push_back('(');
            continue;
        }
        if (a[i] == ')')
        {
            ans.push_back(a[i]);
            continue;
        }
        if (a[i] == 'N')
        {
            std::string b = a.substr(i, 3);
            if (Is_Word(b))
            {
                ans.push_back('!');
                i += 2;
                continue;
            }
        }
        if (a[i] == 'A')
        {
            std::string b = a.substr(i, 3);
            if (Is_Word(b))
            {
                ans.push_back('&');
                i += 2;
                continue;
            }
        }
        if (a[i] == 'O')
        {
            if (a[++i] == 'R')
            {
                ans.push_back('|');
                continue;
            }
        }
        if (a[i] == 'T')
        {
            std::string b = a.substr(i, 4);
            if (Is_Word(b))
            {
                ans.push_back('1');
                i += 3;
                continue;
            }
        }
        if (a[i] == 'F')
        {
            std::string b = a.substr(i, 5);
            if (Is_Word(b))
            {
                ans.push_back('0');
                i += 4;
                continue;
            }
        }
        if (isalpha(a[i])) ans.push_back(a[i]);
    }
    return ans;
}

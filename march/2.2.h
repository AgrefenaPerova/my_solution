#pragma once
#include <iostream>
#include <stack>
#include <string>
bool Its_Operator(char c) {
    return c == '!' || c == '&' || c == '|' ;
}

int Priority(char op) {
    if (op == '!') {
        return 3;
    }
    else if (op == '&') {
        return 2;
    }
    else if (op == '|')
    {
        return 1;
    }
    return 0;
}

std::string infixToPostfix(const std::string& infix) {
    std::string postfix = "";
    std::stack<char> operators;

    for (char c : infix) {
        if (c == ' ') {
            continue;
        }
        else if (isdigit(c) || isalpha(c)) {
            postfix += c;
            postfix += ' ';
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            if (!operators.empty()) {
                operators.pop(); // Discard the '('
            }
        }
        else if (Its_Operator(c)) {
            while (!operators.empty() && Priority(operators.top()) >= Priority(c)) {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        postfix += ' ';
        operators.pop();
    }
    return postfix;

}
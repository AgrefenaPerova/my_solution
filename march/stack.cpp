#include <iostream>
#include <stack>
#include <string>

bool checkBrackets(const std::string& inputString) {
    std::stack<char> bracketStack;
    for (char c : inputString) {
        if (c == '(' || c == '{') {
            bracketStack.push(c);
        }
        else if (c == ')' || c == '}') {
            if (bracketStack.empty()) {
                return false;
            }
            char openBracket = bracketStack.top();
            if ((c == ')' && openBracket != '(') || (c == '}' && openBracket != '{')) {
                return false;
            }
            bracketStack.pop();
        }
    }
    return bracketStack.empty();
}

int main() {
    std::string inputString;
    std::cin >> inputString;
    if (checkBrackets(inputString)) {
        std::cout << "The brackets are placed correctly" << std::endl;
        return 0;
    }
    std::cout << "The brackets are placed incorrectly" << std::endl;
    return 0;
}

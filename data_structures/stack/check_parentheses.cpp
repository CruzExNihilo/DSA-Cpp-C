#include <iostream>
#include <string>
#include <stack>

bool isMatchPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool checkParentheses(const std::string& str){
    std::stack<char> s;
    for(char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            // stack starts from empty
            if (s.empty() || !isMatchPair(s.top(), ch)) return false;
            else s.pop();
        }
    }
    return s.empty();
}

int main() {
    std::string str;
    std::cout << "Enter an expersion with parentheses: ";
    std::getline(std::cin, str);
    
    if (checkParentheses(str)) std::cout << "Matched\n";
    else std::cout<< "Not matched\n";
    
    return 0;
}
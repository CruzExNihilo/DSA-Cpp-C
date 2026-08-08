#include <iostream>
#include <string>
#include <stack>

void reverse(std::string& str) {
    std::stack<char> s;
    for (char ch : str) {
        s.push(ch);
    }

    str.clear();

    while (!s.empty()) {
        str.push_back(s.top());
        s.pop();
    }
}

int main() {
    std::string str;
    std::cout << "Enter a string: " << std::endl;
    std::getline(std::cin, str);

    std::cout << "original string: " << str << std::endl;
    reverse(str);
    std::cout << "reversed string: " << str << std::endl;
    
    return 0;
}
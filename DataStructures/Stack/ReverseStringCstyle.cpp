#include <iostream>
#include <string.h>
#include <stack>

void reverse(char* str) {
    std::stack<char> s;

    size_t len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        s.push(str[i]);
    }

    for (int i = 0; i < len; i++) {
        str[i] = s.top();
        s.pop();
    }
}

int main() {
    char str[50]; // asuuming inputs are of valid size
    std::cout << "Enter a string: " << std::endl;
    fgets(str, sizeof(str), stdin); 
    str[strcspn(str, "\n")] = '\0'; // remove the newline character captured by fgets

    std::cout << "original string: " << str << std::endl;
    reverse(str);
    std::cout << "reversed string: " << str << std::endl;
    
    return 0;
}
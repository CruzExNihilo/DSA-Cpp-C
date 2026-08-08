/**
 * In converting(infix -> postfix), the stack is a temporary holding area of operators and parentheses
 * In evaluating(postfix), the stack stores operands
 * The key is to use stack as a buffer to wait for operators, operands and so on
 * Dijkstra’s Shunting Yard Algorithm -> converting(infix -> postfix)
 */
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>

int precedence(char c) {
    switch (c) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default:  return 0;
    }
}

bool isOperator(char c) {
    return precedence(c) > 0;
}

std::string InfixToPostfix(const std::string& exp) {
    std::stack<char> s;
    std::string output = "";

    size_t i = 0;
    while (i < exp.length()) {
        char c = exp[i];

        if (std::isspace(c)) {
            i++;
            continue;
        }

        // Operand -> straight to output
        if (std::isalnum(c)) {
            while (i < exp.length() && std::isalnum(exp[i])) {
                output.push_back(exp[i]);
                i++;
            }
            output.push_back(' '); // Delimiter so multi-digits stay separate
        }
        // Open '(' -> straight to stack
        else if (c == '(') {
            s.push(c);
            i++;
        }
        // Close ')' -> pop everything until '('
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                output.push_back(s.top());
                output.push_back(' ');
                s.pop();
            }
            if (!s.empty()) s.pop(); // Remove '('
            i++;
        }
        // Operator -> pop stronger operators, THEN push current operator
        else if (isOperator(c)) {
            while (!s.empty() && 
                // left associative
                ((c != '^' && precedence(s.top()) >= precedence(c)) || 
                // right associative 
                (c == '^' && precedence(s.top()) > precedence(c)))) {
                output.push_back(s.top());
                output.push_back(' ');
                s.pop();
            }
            s.push(c);
            i++;
        }
        else {
            i++; // increment for unknown characters
        }
    }

    // Pop any remaining operators
    while (!s.empty()) {
        output.push_back(s.top());
        output.push_back(' ');
        s.pop();
    }

    return output;
}

int evaluatePostfix(const std::string& exp) {
    std::stack<int> s;

    // // for loop version
    // for (size_t i = 0; i < exp.length(); ) {
    //     if (exp[i] == ' ') {
    //         i++;
    //         continue;
    //     }
    //     if (std::isdigit(exp[i])) {
    //         // collect consecutive number
    //         int num = 0;
    //         while (i < exp.length() && std::isdigit(exp[i])) {
    //             num = num * 10 + (exp[i] - '0');
    //             i++;
    //         }
    //         s.push(num);
    //     }
    //     else {
    //         int temp1 = s.top(); s.pop(); // Right operand
    //         int temp2 = s.top(); s.pop(); // Left operand
            
    //         switch (exp[i]) {
    //             case '+': s.push(temp2 + temp1); break;
    //             case '-': s.push(temp2 - temp1); break;
    //             case '*': s.push(temp2 * temp1); break;
    //             case '/': s.push(temp2 / temp1); break;
    //         }
    //         i++;
    //     }
    // }

    size_t i = 0;
    while (i < exp.length()) {
        if (std::isspace(exp[i])) {
            i++;
        }
        else if (std::isdigit(exp[i])) {
            int num = 0;
            // Read rest digits and collect consecutive digits
            while (i < exp.length() && std::isdigit(exp[i])) {
                // convert char to int e.g. '5' - '0' = 53 - 48 = 5
                num = num * 10 + (exp[i] - '0'); 
                i++;
            }
            s.push(num);
        }
        else if (isOperator(exp[i])) {
            // Check stack safety before popping
            if (s.size() < 2) break;

            int temp1 = s.top(); s.pop();
            int temp2 = s.top(); s.pop();
            switch (exp[i]) {
                case '+': s.push(temp2 + temp1); break;
                case '-': s.push(temp2 - temp1); break;
                case '*': s.push(temp2 * temp1); break;
                case '/': s.push(temp2 / temp1); break;
                case '^': s.push(std::pow(temp2, temp1)); break;
            }
            i++;
        }
        else {
            i++;
        }
    }

    return s.empty() ? 0 : s.top();
}

int main() {
    std::string exp;
    std::cout << "Enter an infix expression (e.g. (12 + 3) * 4): ";
    std::getline(std::cin, exp);

    std::string postfix = InfixToPostfix(exp);
    int result = evaluatePostfix(postfix);

    std::cout << "Postfix: " << postfix << "\n";
    std::cout << "Result : " << result << "\n";

    return 0;
}
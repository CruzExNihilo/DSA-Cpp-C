/*vector-based stack */
#include <iostream>
#include <stdexcept>
#include <vector>

using std::vector;

class MyVectorStack{
private:
    vector<int> stack;

public:
    MyVectorStack() = default;
    ~MyVectorStack() = default;

    void push(const int& value) {
        stack.push_back(value);
    }

    void pop() {
        if (isEmpty()) {
            throw std::out_of_range("the stack is empty");
        }
        stack.pop_back();
    }

    int top() {
        if (isEmpty()) {
            throw std::out_of_range("the stack is empty");
        }
        return stack.back();
    }

    size_t size() const {
        return stack.size();
    }

    bool isEmpty() {
        return stack.empty();
    }
};

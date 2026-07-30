/*list-based stack */
#pragma once
#include <stdexcept>
#include <list>

using std::list;

class MyListStack{
private:
    list<int> stack;

public:
    MyListStack() = default;
    ~MyListStack() = default;

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

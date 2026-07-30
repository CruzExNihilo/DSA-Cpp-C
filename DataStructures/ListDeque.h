/*doubly-linked-list-based deque */
#include <iostream>
#include <stdexcept>
#include <list>

using std::list;

class MyListDeque {
private:
    list<int> deque;

public:
    MyListDeque() = default;
    ~MyListDeque() = default;

    void push_front(const int& value) {
        deque.push_front(value);
    }
    
    void pop_front() {
        if (isEmpty()) {
            throw std::out_of_range("deque is empty");
        }
        deque.pop_front();
    }

    void push_back(const int& value) {
        deque.push_back(value);
    }

    void pop_back() {
        if (isEmpty()) {
            throw std::out_of_range("deque is empty");
        }
        deque.pop_back();

    }

    int front() const {
        if (isEmpty()) {
            throw std::out_of_range("deque is empty");
        }
        return deque.front();
    }

    int back() const {
        if (isEmpty()) {
            throw std::out_of_range("deque is empty");
        }
        return deque.back();
    }

    size_t size() const {
        return deque.size();
    }

    bool isEmpty() const{
        return deque.empty();
    }

};
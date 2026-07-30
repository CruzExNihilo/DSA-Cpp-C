/*list-based queue */
#pragma once
#include <stdexcept>
#include <list>
using std::list;

class MyListQueue {
private:
    list<int> queue;

public:
    void enqueue(const int& value) {
        queue.push_back(value);
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("queue is empty");
        } 
        queue.pop_front();
    }

    int front() const {
        if (isEmpty()) {
            throw std::out_of_range("queue is empty");
        } 
        return queue.front();
    }

    size_t size() const {
        return queue.size(); 
    }

    bool isEmpty() const {
        return queue.empty();
    }
};
/*vector-based queue */
#include <iostream>
#include <stdexcept>
#include <vector>

class MyVectorQueue {
private:
    std::vector<int> queue;

public:
    MyVectorQueue() = default;
    ~MyVectorQueue() = default;

    void enqueue(const int& value) {
        queue.push_back(value);
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        queue.erase(queue.begin());
    }

    int front() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
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
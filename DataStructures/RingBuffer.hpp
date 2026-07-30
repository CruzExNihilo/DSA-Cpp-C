#pragma once
#include <vector>
#include <stdexcept>

using std::vector;
using std::move;

class MyCircularQueue {
private:
    size_t front;
    size_t rear;
    vector<int> arr;
    size_t size_;

    void resize(size_t newCapacity) {
        // set minimum size to be 4
        if (newCapacity < 4) newCapacity = 4;
        
        vector<int> newArr(newCapacity); 
        for (size_t i = 0; i < size_; i++) {
            newArr[i] = arr[(front + i) % arr.size()];
        }
        arr = move(newArr);
        front = 0;
        rear = size_;
    }

public:
    MyCircularQueue() : MyCircularQueue(4) {}
    // delegating constructor
    explicit MyCircularQueue(size_t capacity) : 
        front(0), rear(0), arr(capacity < 4 ? 4: capacity), size_(0) {}

    ~MyCircularQueue() = default;

    void addFront(int val) {
        if (isFull()) resize(2 * arr.size());
        // minus 1 to move forward and add size to prevent underflow
        front = (front - 1 + arr.size()) % arr.size();
        arr[front] = val;
        size_++;
    }

    void addRear(int val) {
        if (isFull()) resize(2 * arr.size());
        
        arr[rear] = val;
        rear = (rear + 1) % arr.size();
        size_++;
    }

    void removeFront() {
        if (isEmpty()) throw std::runtime_error("Queue is empty");
        
        front = (front + 1) % arr.size();
        size_--;

        // downsizing(shrinking) after deletion
        if (arr.size() > 4 && size_ < arr.size() / 4) {
            resize(arr.size() / 2);
        }
    }

    void removeRear() {
        if (isEmpty()) throw std::runtime_error("Queue is empty");
        
        rear = (rear - 1 + arr.size()) % arr.size();
        size_--;

        if (arr.size() > 4 && size_ < arr.size() / 4) {
            resize(arr.size() / 2);
        }
    }

    int getFront() const {
        if (isEmpty()) throw std::runtime_error("Queue is empty");
        return arr[front];
    }

    int getRear() const {
        if (isEmpty()) throw std::runtime_error("Queue is empty");
        // add size to prevent rear -1 causing index underflow 
        return arr[(rear - 1 + arr.size()) % arr.size()];
    }
    
    bool isFull() const {
        return size_ == arr.size();
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    size_t size() const {
        return size_;
    }

    size_t capacity() const {
        return arr.size();
    }
};
/*ring-buffer-based deque*/
#pragma once
#include <stdexcept>
#include <vector>

using std::vector;
using std::move;

class MyCircularArrayDeque {
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
    MyCircularArrayDeque() : MyCircularArrayDeque(4) {}
    // delegating constructor
    explicit MyCircularArrayDeque(size_t capacity) : 
        front(0), rear(0), arr(capacity < 4 ? 4: capacity), size_(0) {}

    ~MyCircularArrayDeque() = default;

    // O(1)
    void push_front(const int& value) {
        if (isFull()) resize(2 * arr.size());
        // minus 1 to move forward and add size to prevent underflow
        front = (front - 1 + arr.size()) % arr.size();
        arr[front] = value;
        size_++;
    }

    void push_back(const int& value) {
        if (isFull()) resize(2 * arr.size());
        
        arr[rear] = value;
        rear = (rear + 1) % arr.size();
        size_++;
    }

    // O(1)
    void pop_front() {
        if (isEmpty()) throw std::runtime_error("deque is empty");
        
        front = (front + 1) % arr.size();
        size_--;

        // downsizing(shrinking) after deletion
        if (arr.size() > 4 && size_ < arr.size() / 4) {
            resize(arr.size() / 2);
        }
    }

    void pop_back() {
        if (isEmpty()) throw std::runtime_error("deque is empty");
        
        rear = (rear - 1 + arr.size()) % arr.size();
        size_--;

        if (arr.size() > 4 && size_ < arr.size() / 4) {
            resize(arr.size() / 2);
        }
    }

    int front() const {
        if (isEmpty()) throw std::runtime_error("deque is empty");
        return arr[front];
    }

    int back() const {
        if (isEmpty()) throw std::runtime_error("deque is empty");
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
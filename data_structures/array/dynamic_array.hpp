#pragma once
#include <iostream>
#include <stdexcept>

using std::cout;
using std::cin;

template<typename T>
class DynamicArray {
private:
    T* data;
    int capacity;
    int size;
    static const int INIT_CAP = 4;

    // time complexity -> O(n)
    void resize(int newCap) {
        T* newData = new T[newCap];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCap;
    }

public:

    // construct
    DynamicArray(): capacity(INIT_CAP), size(0){
        data = new T[capacity];
    };


    DynamicArray(int usrCap): capacity(usrCap > 0? usrCap:INIT_CAP), size(0){
        data = new T[capacity];
    }

    // O(n)
    DynamicArray(int usrCap, T& value): capacity(usrCap > 0? usrCap:INIT_CAP), size(capacity){
        data = new T[capacity];
        for (int i = 0; i < size; i++){
            data[i] = value;
        }
    }

    // deconstruct
    ~DynamicArray() {
        delete[] data;
    }

    // add
    void add(const T& value, int index){
        if(!checkPositionIndex(index)){
            throw std::out_of_range("invalid index");
            return;
        }

        if(size == capacity) resize(2*capacity);
        
        // back->front
        for(int  i = size; i > index; i--){
            data[i] = data[i-1];
        }
        data[index] = value;
        size++;
    }

    void push_back(const T& value) {
        add(value, size);
    }

    // delete
    void remove(int index){
        if(!checkElementIndex(index)){
            throw std::out_of_range("invalid index");
        }

        // front->back
        for(int i = index; i < size - 1; i++){
            data[i] = data[i+1];
        }
        size--;
        
        if (size <= capacity / 4 && capacity > INIT_CAP) {
            resize(capacity / 2);
        }
    }

    void pop_back() {
        remove(size-1);    
    }

    // modify
    T& operator[](int index) {
        if(!checkElementIndex(index)){
            throw std::out_of_range("invalid index");
        }
        return data[index];
    }

    // search
    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }
    

    bool checkElementIndex(int index){
        if(index<0 || index > size-1) return false;
        else return true;
    }

    bool checkPositionIndex(int index){
        if(index < 0 || index > size) return false;
        else return true;
    }
};
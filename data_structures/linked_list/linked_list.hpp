#pragma once
#include <stdexcept>

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node() : data(T()), next(nullptr) {}
    Node(const T& x) : data(x), next(nullptr) {}
    ~Node() = default;
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;  // Dummy Node
    int list_size;

public:
    LinkedList() : head(new Node<T>()), list_size(0) {} // head doesn't count into List_size
    
    ~LinkedList() {
        // Delete node by node
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(const int& index, const T& value) {
        if (index < 0 || index > list_size) return;
        
        Node<T>* it = head;
        for (int i = 0; i < index; i++) {  
            it = it->next;
        }
        
        Node<T>* temp = new Node<T>(value);
        temp->next = it->next;
        it->next = temp;
        list_size++;
    }

    void remove(const int& index) {
        if (index < 0 || index >= list_size) return;
        
        Node<T>* it = head;
        for (int i = 0; i < index; i++) {  
            it = it->next;
        }
        
        Node<T>* current = it->next;
        it->next = current->next;
        delete current;
        list_size--;
    }

    Node<T>* at(const int& index) {
        if (index < 0 || index >= list_size) return nullptr;
        
        Node<T>* it = head->next;  
        for (int i = 0; i < index; i++) { 
            it = it->next;
        }
        return it;
    }

    int size() const {
        return list_size;
    }
};
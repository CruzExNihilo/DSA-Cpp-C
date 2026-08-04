#include <iostream>
#include <list>
#include <stack>
#include <algorithm> // For std::swap

void customReverse(std::list<int>& lst) {
    if (lst.size() <= 1) return;

    std::stack<std::list<int>::iterator> s;

    auto it = lst.begin();
    size_t halfSize = lst.size() / 2;

    // push iterators of the FIRST HALF of the list onto the stack
    for (size_t i = 0; i < halfSize; ++i) {
        s.push(it);
        ++it;
    }

    // skip middle element if odd
    if (lst.size() % 2 != 0) {
        ++it;
    }

    // 'it' is at the start of the SECOND HALF. 
    // Pop from the stack (getting the first half in reverse order) and swap values.
    while (!s.empty()) {
        auto firstHalfIt = s.top();
        s.pop();

        std::swap(*firstHalfIt, *it);
        
        ++it;
    }
}

void printList(const std::list<int>& lst) {
    for (int num : lst) {
        std::cout<< num << "->";
    }
    std::cout<< "nullptr" << std::endl;
}

int main() {
    std::list<int> lst;
    int size_;
    std::cout << "Enter the size of the list: ";
    std::cin >> size_;

    for (int i = 0; i < size_; i++) {
        lst.push_back(i);
    }

    std::cout << "original: ";
    printList(lst);

    customReverse(lst);
    std::cout << "reveresd: ";
    printList(lst);

    lst.reverse();
    std::cout << "reveresd: ";
    printList(lst);

    return 0;
}
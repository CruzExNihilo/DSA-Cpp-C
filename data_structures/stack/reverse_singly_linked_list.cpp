#include <iostream>
#include <stack>

struct Node {
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(const int& x): val(x), next(nullptr) {}
    ~Node() = default;
};

class SinglyLinkedList {
private: 
Node* head;
int list_size;

public:
    SinglyLinkedList() {
        head = new Node();
        list_size = 0;
    }

    ~SinglyLinkedList() {
        while (head!= nullptr) {
            Node* temp =head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(int val) {
        Node* temp = new Node(val);
        temp->next = head->next;
        head->next = temp;
        list_size++;
    }

    void printList() {
        Node* it = head->next;
        while (it != nullptr) {
            printf("%d->", it->val);
            it = it->next;
        }
        printf("nullptr\n");
    }

    Node*& getHeadNode() { return head; }
};

void reverse(SinglyLinkedList& list) {
    // assuming passing a valid list
    std::stack<Node*> s;
    Node* head  = list.getHeadNode();
    Node* it = head->next;

    while(it != nullptr) {
        s.push(it);
        it = it->next;
    }

    it = head;
    while(!s.empty()) {
        it->next = s.top();
        s.pop();
        it = it->next;
    }
    it->next = nullptr;
}

int main() {
    SinglyLinkedList list;
    int size_;
    std::cout << "Enter the size of the list: ";
    std::cin >> size_;

    for (int i = 0; i < size_; i++){
        list.push_front(size_-1 -i);
    }
    std::cout << "original list: ";
    list.printList();

    reverse(list);

    std::cout << "reveresd list: ";
    list.printList();
    return 0;
}

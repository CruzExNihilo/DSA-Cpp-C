// iterative
#include <iostream>

class BST{
private:
    struct Node{
        int data;
        Node* leftNode;
        Node* rightNode;
        Node(): data(0), leftNode(nullptr), rightNode(nullptr) {}
        Node(const int& val): data(val), leftNode(nullptr), rightNode(nullptr) {}
        ~Node() = default;
    };
    Node* root;

    Node* NewNode(const int& val) {
        return new Node(val);
    }

    void destroyTree(Node* node) {
        if (node == nullptr) return;
        destroyTree(node->leftNode);
        destroyTree(node->rightNode);
        delete node;
    }

public:
    BST(): root(nullptr){}
    ~BST() {
        destroyTree(root);
    }
    

    void insert(const int& val){
        if (root == nullptr) {
            root = NewNode(val);
            return;
        }

        Node* current = root;
        while(true) {
            if(val < current->data) {
                if( current->leftNode == nullptr) {
                    current->leftNode = NewNode(val);
                    break;
                }
                current = current->leftNode;
            }
            else if(val > current->data) {
                if( current->rightNode == nullptr) {
                    current->rightNode = NewNode(val);
                    break;
                }
                current = current->rightNode;
            }
            else {
                break;
            }
        }
    }

    bool search(const int& val) const {
        Node* current = root;
        while(current != nullptr) {
            if(val < current->data) {
                current = current->leftNode;
            }
            else if(val > current->data) {
                current = current->rightNode;
            }
            else return true;
        }
        return false;
    }

    int findMin() const {
        if (root == nullptr) {
            std::cout << "empty tree\n";
            return -1;
        }

        Node* current = root;
        while(current->leftNode != nullptr) {
            current = current->leftNode;
        }

        return current->data;
    }

    int findMax() const {
        if (root == nullptr) {
            std::cout << "empty tree\n";
            return -1;
        }

        Node* current = root;
        while(current->rightNode != nullptr) {
            current = current->rightNode;
        }

        return current->data; 
    }
};
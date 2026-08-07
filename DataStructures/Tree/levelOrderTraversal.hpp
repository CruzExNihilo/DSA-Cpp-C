/* BST : level order traversal or BFT(breadth-first traversal)*/

#include <iostream>
#include <queue>
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

    void levelOrder(Node* node) {
        if (node == nullptr) {
            return;
        }
        std::queue<Node*> Q;
        Q.push(node);
        while(!Q.empty()) {
            Node* current = Q.front();
            std::cout << current->data << " ";
            // enqueue next level subtrees
            if (current->leftNode != nullptr) Q.push(current->leftNode);
            if (current->rightNode != nullptr) Q.push(current->rightNode);
            // move on to sibling or next level
            Q.pop();
        }
    }
    
    Node* insert(Node* node, const int& val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->leftNode = insert(node->leftNode, val); 
        } 
        else if (val > node->data) {
            node->rightNode = insert(node->rightNode, val);
        }
        return node;
    }

public:
    BST(): root(nullptr){}
    ~BST() {
        destroyTree(root);
    }

    void levelOrder() {
        levelOrder(root);
    }

    void insert(const int& val){
        root = insert(root, val);
    }
};
/**
 * BST : depth-first traversal 
 * preorder: <data><left><right> -> DLR
 * inorder: <left><data><right> -> LDR
 * postorder: <left><right><data> -> LRD
 * time complexity: O(N)
 * space complexity: O(h), h for the maximum height of the tree 
 * - O(N-1) in the worst case(skewed tree or linked list)
 * - O(logN) in the best case(balanced binary tree)
 */
#include <iostream>

typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

void Preorder(Node* node) {
    if (node == nullptr) return;
    std::cout << node->data <<" ";
    Preorder(node->left);
    Preorder(node->right);
}

void Inorder(Node* node) {
    if (node == nullptr) return;
    Preorder(node->left);
    std::cout << node->data <<" ";
    Preorder(node->right);
}

void Postorder(Node* node) {
    if (node == nullptr) return;
    Preorder(node->left);
    Preorder(node->right);
    std::cout << node->data <<" ";
}
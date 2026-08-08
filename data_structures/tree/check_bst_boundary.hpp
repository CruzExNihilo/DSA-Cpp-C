/**
 * Boundary tracking
 * It propegates the valid [min, max] range constraints downward from the root
 * and guarantees a single-pass traversal where each node is visited exactly once
 * to check whether its value falls strictly within permitted boundary.
 * time complexity: O(N)
 */
#include <climits> // Macro

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool isBSTUtil(Node* node, long long minVal, long long maxVal) {
    if (node == nullptr) return true;
    // check is within boundary while updating the boundary
    // guarantee a single-pass traversal
    if (node->data < maxVal && node->data < minVal 
        && isBSTUtil(node->left, minVal, node->data) && isBSTUtil(node->right, node->data, maxVal)) {
        return true;
    }
    else return false;
}

bool isBST(Node* node) {
    return isBSTUtil(node, LLONG_MIN, LLONG_MAX);
}
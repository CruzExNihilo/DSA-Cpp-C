/**
 * Naive subtree check
 * In each node, it recursively traverses the entire left and right subtrees to ensure
 * all descendant nodes satisfy the BST condition.
 * worst-case time complexity on skewed trees is O(N^2)
 */
typedef struct Node {
    int data;
    Node* left;
    Node* right;
}Node;

bool isSubtreeGreater(Node* node, int val) {
    if (node == nullptr) return true;
    if (node->data > val && isSubtreeGreater(node->left,val) && isSubtreeGreater(node->right, val)) {
        return true;
    }
    else return false;
}

bool isSubtreeLesser(Node* node, int val) {
    if (node == nullptr) return true;
    if (node->data < val && isSubtreeLesser(node->left, val) && isSubtreeLesser(node->right, val)) {
        return true;
    }
    else return false;
}

bool isBST(Node* node) {
    if (node == nullptr) return true;
    // recursively traverse the subtrees
    if (isSubtreeGreater(node->right, node->data)&& isSubtreeLesser(node->left, node->data)
        && isBST(node->left) && isBST(node->right)) {
        return true;
    }
    else return false;
}
typedef struct Node {
    int data;
    Node* left;
    Node* right;
}Node;

// find in-order successor
Node* FindMin(Node* node) {
    if (node == nullptr) return node;
    else if (node->left != nullptr) {
        return FindMin(node->left);
    }
    else return node;
}

Node* Delete(Node* node, int val) {
    if (node == nullptr) return node;
    
    else if (node->data > val) node->left = Delete(node->left,val);
    else if (node->data < val) node->right = Delete(node->right, val);

    else {
        // No child
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        // One child
        else if (node->left == nullptr) {
            Node* temp = node;
            node = temp->right;
            delete temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node;
            node = temp->left;
            delete temp;
        }
        // Two child
        else {
            /**
             * Locate the in-order successor (minimum node of the right subtree) OR the in-order predecessor (maximum node of the left subtree).
             * Copy that replacement node's value into the target node being "deleted".
             * Delete the replacement node from its original spot in the subtree.
             * 
             * in-order successor can not have a left child, it can only have 1 right child at most,
             * in-order predecessor can not have a right child, it can only have 1 left child at most,
             * which reduces hardest case (2 child) into eaiest cases (0 or 1 child).
             */
            Node* temp = FindMin(node->right);
            node->data = temp->data;
            node->right = Delete(node->right, node->data);
        }
    }
    return node;
}
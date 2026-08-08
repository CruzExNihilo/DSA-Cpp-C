typedef struct Node {
    int data;
    Node* left;
    Node* right;
}Node;

Node* Find(Node* node, int val) {
    if(node == nullptr) return node;
    else if (node->data < val) return Find(node->right, val);
    else if (node->data > val) return Find(node->left, val);
    else return node;
}

Node* FindMin(Node* node) {
    if (node == nullptr) return node;

    else if (node->left != nullptr) {
        return FindMin(node->left);
    }

    else return node;
}

Node* GetSuccessor(Node* node, int val) {
    if (node == nullptr) return node;

    Node* current = Find(node, val);
    if (current == nullptr) return current;

    // case 1: has right subtree
    if(current->right != nullptr) {
        return FindMin(current->right);
    }
    // case 2: no right subtree
    else {
        Node* successor = nullptr;
        Node* it = node;
        // Turning left means 'it' > val. Since target has no right subtree, 
        // target is the rightmost/largest node in 'it's left subtree 
        // (either as 'it->left' directly or deep in 'it->left's right spine).
        // Thus, the LAST ancestor we turned left at is the immediate successor.
        // Or Target is the max node in 'successor's left subtree.
        while(it->data != current->data) {
            // Track the last ancestor where we turned left
            if(it->data > val) {
                successor = it;
                it = it->left;
            }
            // go right without updating the successor since it is inorder traversal
            else {
                it = it->right;
            }
        }
        return successor;
    }
}
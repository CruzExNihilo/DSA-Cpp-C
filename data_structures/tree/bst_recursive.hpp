// recursive
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

    bool search(Node* node, const int& val) const {
        if (node == nullptr) {
            return false;
        }
        if(val == node->data) return true;        
        if (val < node->data) {
            return search(node->leftNode, val);
        } else {
            return search(node->rightNode, val);
        }
    }

    int findMin(Node* node) const{
        if(node == nullptr) return -1;
        if(node->leftNode == nullptr) {
            return node->data;
        }
        return findMin(node->leftNode);
    }

    int findMax(Node* node) const{
        if(node == nullptr) return -1;
        if(node->rightNode == nullptr) {
            return node->data;
        }
        return findMax(node->rightNode);
    }

    int max(const int& num1, const int& num2) const {
        return num1 > num2 ? num1 : num2;
    }

    int findHeight(Node* node) const {
        if (node == nullptr) return -1;
        int leftH = findHeight(node->leftNode);
        int rightH = findHeight(node->rightNode);
        return max(leftH, rightH) + 1;
    }


public:
    BST(): root(nullptr){}
    ~BST() {
        destroyTree(root);
    }

    void insert(const int& val){
        root = insert(root, val);
    }

    bool search(const int& val) const {
        return search(root, val);
    }

    int findMin() const {
        return findMin(root);
    }

    int findMax() const {
        return findMax(root);
    }

    int findHeight() const {
        return findHeight(root);
    }
};
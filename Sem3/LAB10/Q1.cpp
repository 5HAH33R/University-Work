#include <iostream>
#include <algorithm>

using namespace std;

class AVLTree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        int height;
        Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };
    
    Node* root;

    int height(Node* node) {
        return node ? node->height : 0;
    }


    int balanceFactor(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    void updateHeight(Node* node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }

    // Right rotation
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Left rotation
    Node* rotateLeft(Node* torotate) {
        Node* y = torotate->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = torotate;
        torotate->right = T2;

        // Update heights
        updateHeight(torotate);
        updateHeight(y);

        return y;
    }

    // Balance the tree after an operation
    Node* balance(Node* node) {
        updateHeight(node);
        int balance = balanceFactor(node);

        // Left heavy (LL or LR)
        if (balance > 1) {
            if (balanceFactor(node->left) < 0) { // Left-Right case
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node); // Left-Left case
        }

        // Right heavy (RR or RL)
        if (balance < -1) {
            if (balanceFactor(node->right) > 0) { // Right-Left case
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node); // Right-Right case
        }
        
        return node; // Balanced
    }

    
    Node* InorderSucc(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        } else {
            return node; // Duplicate keys are not inserted
        }

        return balance(node);
    }

    // Recursive deletion logic
    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) {
            return node;
        }

        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        } else {
            // Node to be deleted found

            // Case 1 & 2: Node with only one child or no child
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ? node->left : node->right;
                
                if (temp == nullptr) { // No child case (Leaf node)
                    temp = node;
                    node = nullptr;
                } else { // One child case
                    *node = *temp; // Copy content of non-empty child
                }
                delete temp;
            } else {
                // Case 3: Node with two children
                Node* temp = InorderSucc(node->right); // Get inorder successor
                
                // Copy the successor's data to this node
                node->key = temp->key;
                
                // Delete the inorder successor
                node->right = deleteNode(node->right, temp->key);
            }
        }

        if (node == nullptr) {
            return node;
        }
        
        return balance(node);
    }

    void inOrder(Node* node) {
        if (!node) return;
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;
    
    // Insert operations to build the tree
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(20); // Duplicate key check (should be ignored)
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "In-order traversal before deletion: ";
    tree.inOrder(); // Expected: 10 20 25 30 40 50 

    // Delete a key
    tree.deleteKey(20);

    cout << "In-order traversal after deleting 20: ";
    tree.inOrder(); // Expected: 10 25 30 40 50 

    return 0;
}
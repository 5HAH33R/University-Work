#include <bits/stdc++.h>

using namespace std;

class EmployeeNode {
    int id;
    string name;
    string department;
    EmployeeNode *left;
    EmployeeNode *right;
    EmployeeNode(int i, string n, string d) : id(i), name(n), department(d), left(NULL), right(NULL) {}
};

class EmployeeBST {
private:
    EmployeeNode* root;

    EmployeeNode* insertRec(EmployeeNode* node, int id, string name, string department) {
        if (node == NULL) {
            return new EmployeeNode(id, name, department);
        }
        if (id < node->id) {
            node->left = insertRec(node->left, id, name, department);
        } else if (id > node->id) {
            node->right = insertRec(node->right, id, name, department);
        }
        return node;
    }

    void inOrderRec(EmployeeNode* node) {
        if (node != NULL) {
            inOrderRec(node->left);
            cout << "ID: " << node->id << ", Name: " << node->name << ", Dept: " << node->department << endl;
            inOrderRec(node->right);
        }
    }

    EmployeeNode* findMinNode(EmployeeNode* node) {
        EmployeeNode* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    EmployeeNode* deleteNodeRec(EmployeeNode* node, int id) {
        if (node == NULL) {
            return node;
        }

        if (id < node->id) {
            node->left = deleteNodeRec(node->left, id);
        } else if (id > node->id) {
            node->right = deleteNodeRec(node->right, id);
        } else {
            if (node->left == NULL) {
                EmployeeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                EmployeeNode* temp = node->left;
                delete node;
                return temp;
            }
            
            EmployeeNode* temp = findMinNode(node->right);
            node->id = temp->id;
            node->name = temp->name;
            node->department = temp->department;
            node->right = deleteNodeRec(node->right, temp->id);
        }
        return node;
    }

public:
    EmployeeBST() : root(NULL) {}

    void insert(int id, string name, string department) {
        root = insertRec(root, id, name, department);
    }

    void search(int id) {
        EmployeeNode* current = root;
        while (current != NULL) {
            if (id == current->id) {
                cout << "Found Employee ID " << id << ": Name: " << current->name << ", Dept: " << current->department << endl;
                return;
            } else if (id < current->id) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        cout << "Employee with ID " << id << " not found." << endl;
    }

    void deleteNode(int id) {
        root = deleteNodeRec(root, id);
        cout << "Attempted deletion of Employee ID " << id << "." << endl;
    }

    void inOrderTraversal() {
        if (root == NULL) {
            cout << "The tree is empty." << endl;
            return;
        }
        cout << "--- In-Order Traversal (Ascending ID) ---" << endl;
        inOrderRec(root);
    }

    void findMin() {
        EmployeeNode* minNode = findMinNode(root);
        if (minNode == NULL) {
            cout << "The tree is empty." << endl;
        } else {
            cout << "Minimum ID Employee: ID: " << minNode->id << ", Name: " << minNode->name << ", Dept: " << minNode->department << endl;
        }
    }

    void findMax() {
        EmployeeNode* current = root;
        if (current == NULL) {
            cout << "The tree is empty." << endl;
            return;
        }
        while (current->right != NULL) {
            current = current->right;
        }
        cout << "Maximum ID Employee: ID: " << current->id << ", Name: " << current->name << ", Dept: " << current->department << endl;
    }
};

int main() {
    EmployeeBST bst;

    bst.insert(50, "Alice Smith", "HR");
    bst.insert(30, "Bob Johnson", "Engineering");
    bst.insert(70, "Charlie Brown", "Sales");
    bst.insert(20, "David Lee", "Engineering");
    bst.insert(40, "Eve Davis", "HR");
    bst.insert(60, "Frank Green", "Sales");
    bst.insert(80, "Grace Hall", "Marketing");

    bst.inOrderTraversal();

    bst.search(40);

    bst.search(99);

    bst.findMin();

    bst.findMax();

    bst.deleteNode(20);
    bst.deleteNode(70);
    bst.deleteNode(50);
    
    bst.inOrderTraversal();

    return 0;
}
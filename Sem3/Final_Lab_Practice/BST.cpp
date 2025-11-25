#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(NULL), right(NULL){}
};

class BST{
    public:
    Node* root;

    BST(): root(NULL){}

    void insert(int key){
        root = insertinbst(root, key);
    }

    void deleteNode(int key){
        root = deleteinbst(root , key);
    }

    void inOrder(){
        inordertree(root);
    }



    private:

    Node* insertinbst(Node* node, int key){
        if(node == NULL){
            Node* NewNode = new Node(key);
            return NewNode;
        }

        if(key < node->val){
            node->left = insertinbst(node->left,key);
        }
        else if(key> node->val){
            node->right = insertinbst(node->right,key);
        }

        return node;
    }

    Node* GetInorderSuccessor(Node* node){
        node = node->left;
        while(node->right != NULL){
            node = node->right;
        }
        return node;
    }

    Node* deleteinbst(Node* node, int key){
        if(node == NULL){
            return node;
        }

        if(key < node->val){
            node->left = deleteinbst(node->left,key);
        }
        else if(key> node->val){
            node->right = deleteinbst(node->right,key);
        }
        else{
            if(node->left == NULL){
                Node* temp = new Node(node->right->val);
                delete node;
                return temp;
            }
            else if(node->right == NULL){
                Node* temp = new Node(node->left->val);
                delete node;
                return temp;
            }
            // if two children
            Node* temp = GetInorderSuccessor(node);
            node->val = temp->val;
            node->left = deleteinbst(node->left, temp->val);
        }
        return node;
    }

    void inordertree(Node* node){
        if(node != NULL){
            inordertree(node->left);
            cout << node->val << " ";
            inordertree(node->right);
        }
    }

};

int main(){
    BST tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    tree.inOrder();

}
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    int height;

    Node(int v) : val(v), left(NULL),right(NULL), height(1){}
};

class AVLTree{
    private:
    Node* root;
    int height(Node* node){
        if(node){
            return node->height;
        }
        else{
            return 0;
        }
    }

    int balanceFactor(Node* node){
        return height(node->left) - height(node->right);
    }

    void updateHeight(Node* node){
        node->height = 1+ max(height(node->left), height(node->right));
    }

    Node* rotateright(Node* node){
        Node* tochange = node;
        node = node->left;
        Node* temp = node->right;
        node->right = tochange;
        tochange->left = temp;

        updateHeight(tochange);
        updateHeight(node);

        return node;
    }

    Node* rotateleft(Node* node){
        Node* tochange = node;
        node = node->right;
        Node* temp = node->left;
        node->left = tochange;
        tochange->right = temp;

        updateHeight(tochange);
        updateHeight(node);

        return node;
    }

    Node* balance(Node* node){
        int balance = balanceFactor(node);
        updateHeight(node);
        // left heavy
        if(balance > 1){
            if(balanceFactor(node->left) < 0){ //left-right
                node->left = rotateleft(node->left);
            }
            return rotateright(node); // left-left 
        }

        if(balance < -1){
            if(balanceFactor(node->right) > 0 ){
                node->right = rotateright(node->right); //right-left
            }
            return rotateleft(node); // right-right
        }

        return node;
    }

    Node* insert(Node* node, int val){
        if(node == NULL){
            Node* NewNode = new Node(val);
            return NewNode;
        }

        if(val < node->val){
            node->left = insert(node->left,val);
        }
        else if(val > node->val){
            node->right = insert(node->right,val);
        }
        else{
            return node;
        }

        return balance(node);


    }

    Node* GetInorderPredeccessor(Node* node){
        node = node->left;
        while(node->right != NULL){
            node= node->right;
        }
        return node;


    }

    Node* deletenode(Node* node, int key){
        if(node == NULL){
            return node;
        }

        if(key < node->val){
            node->left = deletenode(node->left,key);
        }
        else if(key > node->val){
            node->right = deletenode(node->right,key);
        }
        else{
            if(node->left == NULL){
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == NULL){
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = GetInorderPredeccessor(node);
            node->val = temp->val;
            node->left = deletenode(node->left,temp->val);
        }
        return balance(node);
    }
    void inorder(Node* node){
        if(!node) return;

        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);

    }

    public:
    AVLTree(): root(NULL){}

    void AvlInsert(int val){
        root = insert(root , val);
    }

    void AvlDelete(int val){
        root = deletenode(root,val);
    }

    void Inorder(){
        inorder(root);
    }


};

int main(){
    AVLTree test;
    test.AvlInsert(23);
    test.AvlInsert(32);
    test.AvlInsert(21);
    test.AvlInsert(15);

    test.Inorder();

}
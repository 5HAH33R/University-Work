#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* Node = root;
    while(true){
        if(Node == NULL) return Node;
        if(Node->val == p->val){
            return p;
        }
        if(Node->val == q->val){
            return q;
        }
        if(Node->val < p->val && Node->val < q->val){
            Node = Node->right;
        }
        else if(Node->val > p->val && Node->val > q->val){
            Node = Node->left;
        }
        else{
            return Node;
        }
    }
}

TreeNode* insertNode(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else if (val > root->val) {
        root->right = insertNode(root->right, val);
    }
    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    TreeNode* current = root;
    while (current != NULL) {
        if (val == current->val) {
            return current;
        } else if (val < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

int main() {
    vector<int> keys = {6, 2, 8, 0, 4, 7, 9, 3, 5};
    TreeNode* root = NULL;

    for (int key : keys) {
        root = insertNode(root, key);
    }


    
    TreeNode* p1 = findNode(root, 3);
    TreeNode* q1 = findNode(root, 5);
    TreeNode* result1 = lowestCommonAncestor(root, p1, q1);
    cout << result1->val << endl;

    return 0;
}
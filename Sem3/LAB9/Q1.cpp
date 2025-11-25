#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* findMin(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
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


TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}


vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> postorder;
    if(root == NULL) return postorder;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        postorder.push_back(root->val);
        if(root->left != NULL){
            st.push(root->left);
        }
        if(root->right != NULL){
            st.push(root->right);
        }
    }
    reverse(postorder.begin(),postorder.end());
    return postorder;
}

vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> preorder;
    if(root == NULL) return preorder;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        preorder.push_back(root->val);
        if(root->right != NULL){
            st.push(root->right);
        }
        if(root->left != NULL){
            st.push(root->left);
        }
    }
    return preorder;
}


void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

int main() {
    TreeNode* root = NULL;
    vector<int> initial_keys = {45, 20, 60, 10, 30, 50, 70, 65};

    for (int key : initial_keys) {
        root = insertNode(root, key);
    }

    cout << "Keys Inserted: ";
    printVector(initial_keys);
    cout << endl;
    
    cout << "Preorder: ";
    printVector(preorderTraversal(root));
    cout << endl;

    cout << "Postorder: ";
    printVector(postorderTraversal(root));
    cout << endl;

    return 0;
}
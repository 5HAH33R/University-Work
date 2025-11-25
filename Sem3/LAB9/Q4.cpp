#include <bits/stdc++.h>

using namespace std;

class TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

int sumNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return root->val + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    vector<int> keys = {10, 5, 15, 2, 7, 12, 17, 1, 9};
    TreeNode* root = NULL;

    for (int key : keys) {
        root = insertNode(root, key);
    }

    int totalSum = sumNodes(root);
    cout << totalSum << endl;

    return 0;
}   
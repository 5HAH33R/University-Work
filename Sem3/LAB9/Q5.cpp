#include <bits/stdc++.h>

using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* prevNode = nullptr;

TreeNode* insertNode(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else if (val > root->val) {
        root->right = insertNode(root->right, val);
    }
    return root;
}

int getMinimumDifference(TreeNode* root) {
    if (root == nullptr) {
        return INT_MAX;
    }
    
    int ans = INT_MAX;
    
    ans = min(ans, getMinimumDifference(root->left));

    if (prevNode != nullptr) {
        ans = min(ans, root->val - prevNode->val);
    }
    prevNode = root;
    
    ans = min(ans, getMinimumDifference(root->right));

    return ans;
}

int main() {
    vector<int> keys = {10, 5, 15, 2, 7, 12, 17, 1, 9};
    TreeNode* root = NULL;

    for (int key : keys) {
        root = insertNode(root, key);
    }

    int ans = getMinimumDifference(root);
    cout << ans << endl;

    return 0;
}
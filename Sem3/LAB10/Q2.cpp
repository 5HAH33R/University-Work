#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* RecurFunc(vector<int>& nums, int st, int end){
    if(st > end) return NULL;
    int mid = st + (end - st) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = RecurFunc(nums, st, mid - 1);
    root->right = RecurFunc(nums, mid + 1, end);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return RecurFunc(nums, 0, nums.size() - 1);
}


void inOrder(TreeNode* node) {
    if (!node) return;
    inOrder(node->left);
    cout << node->val << " ";
    inOrder(node->right);
}


int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = sortedArrayToBST(nums);
    inOrder(root);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int max_diameter = 0;

int FindDiameterUsingHeight(TreeNode* root){
    if(root == nullptr) return 0;

    int lefth = FindDiameterUsingHeight(root->left);
    int righth = FindDiameterUsingHeight(root->right);
    max_diameter = max(max_diameter , lefth + righth);

    return 1 + max(lefth, righth);
}

int diameterOfBinaryTree(TreeNode* root) {
    max_diameter = 0; 
    FindDiameterUsingHeight(root);
    return max_diameter;
}


void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->left->left = new TreeNode(9); 
    root1->left->right = new TreeNode(5);

    int result1 = diameterOfBinaryTree(root1);
    cout << "Tree 1 Diameter: " << result1;
    return 0;
}
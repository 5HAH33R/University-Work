#include <bits/stdc++.h>

using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* sortedListToBST(ListNode* head) {
    if(head == nullptr) return nullptr;
    if(head->next == nullptr) return new TreeNode(head->val);
    
    ListNode* prev = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast != nullptr && fast->next != nullptr){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    TreeNode* rootNode = new TreeNode(slow->val);

    if (prev != nullptr) {
        prev->next = nullptr;
        rootNode->left = sortedListToBST(head);
    }

    rootNode->right = sortedListToBST(slow->next);
    
    return rootNode;
}

ListNode* createLinkedList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

void printPreorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> nums1 = {-10, -3, 0, 5, 9};
    ListNode* head1 = createLinkedList(nums1);
    
    TreeNode* bstRoot1 = sortedListToBST(head1);

    cout << "Input List: -10, -3, 0, 5, 9" << endl;
    printInorder(bstRoot1);
    cout << endl;
    cout << "BST Preorder: ";
    printPreorder(bstRoot1);
    cout << endl << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7};
    ListNode* head2 = createLinkedList(nums2);
    
    TreeNode* bstRoot2 = sortedListToBST(head2);

    cout << "Input List: 1, 2, 3, 4, 5, 6, 7" << endl;
    printInorder(bstRoot2);
    cout << endl;
    cout << "BST Preorder: ";
    printPreorder(bstRoot2);
    cout << endl;

    return 0;
}
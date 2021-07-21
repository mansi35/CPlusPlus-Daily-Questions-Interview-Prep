/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* inorder(vector<int> list, int i, int j) {
        if (i > j)
            return NULL;
        int mid = (i + j) / 2;
        TreeNode* root = new TreeNode(list[mid]);
        root->left = inorder(list, i, mid-1);
        root->right = inorder(list, mid+1, j);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> list;
        while (head != NULL) {
            list.push_back(head->val);
            head = head->next;
        }
        return inorder(list, 0, list.size()-1);
    }
};
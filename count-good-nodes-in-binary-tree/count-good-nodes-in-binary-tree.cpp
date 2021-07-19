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
    void countGoodNodes(TreeNode* root, int maxInPath, int& count) {
        if (root == NULL)
            return;
        if (root->val >= maxInPath) {
            maxInPath = root->val;
            count++;
        }
        countGoodNodes(root->left, maxInPath, count);
        countGoodNodes(root->right, maxInPath, count);
    }
    
    int goodNodes(TreeNode* root) {
        int count  = 0;
        countGoodNodes(root, root->val, count);
        return count;
    }
};
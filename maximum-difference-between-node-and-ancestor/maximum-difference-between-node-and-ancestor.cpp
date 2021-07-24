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
    int maxAncestorDiffHelper(TreeNode* node, int curMax, int curMin) {
        if (node == NULL) {
            return curMax - curMin;
        }
        curMax = max(curMax, node->val);
        curMin = min(curMin, node->val);
        int left = maxAncestorDiffHelper(node->left, curMax, curMin);
        int right = maxAncestorDiffHelper(node->right, curMax, curMin);
        return max(left, right);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return maxAncestorDiffHelper(root, root->val, root->val);
    }
};
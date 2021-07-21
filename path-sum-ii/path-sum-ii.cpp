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
    void pathSumHelper(TreeNode* root, int targetSum, vector<int> path, vector<vector<int>>& paths) {
        if (root == NULL)
            return;
        if (targetSum == root->val and root->left == NULL and root->right == NULL) {
            path.push_back(root->val);
            paths.push_back(path);
            return;
        }
        path.push_back(root->val);
        pathSumHelper(root->left, targetSum - root->val, path, paths);
        pathSumHelper(root->right, targetSum - root->val, path, paths);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return vector<vector<int>>();
        }
        vector<int> path;
        vector<vector<int>> paths;
        pathSumHelper(root, targetSum, path, paths);
        return paths;
    }
};
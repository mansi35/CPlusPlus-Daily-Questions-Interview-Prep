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
    int treeHeight(TreeNode* root) {
        if (root == NULL)
            return 0;
        return max(treeHeight(root->left), treeHeight(root->right)) + 1;
    }
    
    void addKthLevel(vector<int>& v, TreeNode* root, int k, int dir) {
        if (root == NULL)
            return;
        if (k == 1) {
            v.push_back(root->val);
        }
        if (dir == 1) {
            addKthLevel(v, root->left, k-1, dir);
            addKthLevel(v, root->right, k-1, dir);
        } else {
            addKthLevel(v, root->right, k-1, dir);
            addKthLevel(v, root->left, k-1, dir);
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int height = treeHeight(root);
        vector<vector<int>> zigzagTree;
        for (int i = 1; i <= height; i++) {
            vector<int> v;
            addKthLevel(v, root, i, i % 2);
            zigzagTree.push_back(v);
        }
        return zigzagTree;
    }
};
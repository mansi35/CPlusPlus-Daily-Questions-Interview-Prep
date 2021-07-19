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
    pair<int, int> fastDiameter(TreeNode* root) {
        pair<int, int> treeSpec;
        if (root == NULL) {
            treeSpec.first = treeSpec.second = 0;
            return treeSpec;
        }
        pair<int, int> leftTreeSpec = fastDiameter(root->left);
        pair<int, int> rightTreeSpec = fastDiameter(root->right);
        
        treeSpec.first = 1 + max(leftTreeSpec.first, rightTreeSpec.first);
        treeSpec.second = max(leftTreeSpec.first + rightTreeSpec.first, max(leftTreeSpec.second, rightTreeSpec.second));
        return treeSpec;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> treeSpec = fastDiameter(root);
        return treeSpec.second;
    }
};
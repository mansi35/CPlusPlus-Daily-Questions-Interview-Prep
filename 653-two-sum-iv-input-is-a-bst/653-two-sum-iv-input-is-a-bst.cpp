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
    void inorder(vector<int>& nums, TreeNode* root) {
        if (root == NULL)
            return;
        inorder(nums, root->left);
        nums.push_back(root->val);
        inorder(nums, root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(nums, root);
        unordered_map<int, int> umap;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (umap.find(k - nums[i]) != umap.end()) {
                return true;
            }
            umap[nums[i]] = i + 1;
        }
        return false;
    }
};
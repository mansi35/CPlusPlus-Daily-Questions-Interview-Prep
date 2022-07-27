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
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (left != 0 and nums[left] == nums[left-1]) {
                left++;
                continue;
            }
            int sum = nums[left] + nums[right];
            if (sum == k) {
                return true;
            }
            else if (sum < k)
                left++;
            else
                right--;
        }
        return false;
    }
};
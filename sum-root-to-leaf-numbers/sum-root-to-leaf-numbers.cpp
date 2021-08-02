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
    void sumNumbersHelper(TreeNode* root, string num, int& sum) {
        if (root == NULL)
            return;
        if (root->left == NULL and root->right == NULL) {
            num += to_string(root->val);
            sum += stoi(num);
            return;
        }
        num += to_string(root->val);
        sumNumbersHelper(root->left, num, sum);
        sumNumbersHelper(root->right, num, sum);
    }
    
    int sumNumbers(TreeNode* root) {
        if (root == NULL)
            return 0;
        int result = 0;
        string num;
        sumNumbersHelper(root, num, result);
        return result;
    }
};
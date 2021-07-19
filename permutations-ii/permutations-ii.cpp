class Solution {
public:
    void permuteHelper(vector<int>& nums, int i, vector<vector<int>>& ans) {
        if (i == nums.size() and find (ans.begin(), ans.end(), nums) == ans.end()) {
            ans.push_back(nums);
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            permuteHelper(nums, i+1, ans);
            swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        permuteHelper(nums, 0, result);
        return result;
    }
};
class Solution {
public:
    void subsetsHelper(vector<int>& nums, vector<int>& subset, vector<vector<int>>& result, int i) {
        if (i == nums.size()) {
            result.push_back(subset);
            return;
        }
        result.push_back(subset);
        for (int j = i; j < nums.size(); j++) {
            subset.push_back(nums[j]);
            subsetsHelper(nums, subset, result, j+1);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> result;
        subsetsHelper(nums, subset, result, 0);
        return result;
    }
};
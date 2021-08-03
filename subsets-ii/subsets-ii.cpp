class Solution {
    unordered_map<int, bool> visited;
public:
    void subsetsHelper(vector<int>& nums, vector<int>& subset, vector<vector<int>>& result, int i) {
        bool flag = false;
        for (auto s: result) {
            if (s == subset) {
                flag = true;
            }
        }
        if (i == nums.size() && !flag) {
            result.push_back(subset);
            return;
        }
        if (!flag)
            result.push_back(subset);
        for (int j = i; j < nums.size(); j++) {
            subset.push_back(nums[j]);
            subsetsHelper(nums, subset, result, j+1);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> result;
        subsetsHelper(nums, subset, result, 0);
        return result;
    }
};
class Solution {
public:
    void combinationSum3Helper(vector<vector<int>>& result, vector<int>& combination, int k, int target, int index) {
        if (target == 0 and k == 0) {
            result.push_back(combination);
        }
        if (target <= 0 or k <= 0)
            return;
        for (int i = index; i <= 9; i++) {
            combination.push_back(i);
            combinationSum3Helper(result, combination, k-1, target - i, i + 1);
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        combinationSum3Helper(result, combination, k, n, 1);
        return result;
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2)
            return false;
        int target = total / 2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1));
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                if (i == 0 and j == 0)
                    dp[i][j] = true;
                else if (i == 0 and j != 0)
                    dp[i][j] = false;
                else if (i != 0 and j == 0)
                    dp[i][j] = true;
                else if (j >= nums[i-1])
                    dp[i][j] = dp[i-1][j-nums[i-1]] or dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[nums.size()][target];
    }
};
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d + 1, vector<int>(target + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= d; i++) {
            for (int j = 1; j <= target; j++) {
                int count = 0;
                for (int k = 1; k <= min(f, j); k++) {
                    count = (count + dp[i - 1][j - k]) % 1000000007;
                }
                dp[i][j] = count;
            }
        }
        
        return dp[d][target];
    }
};
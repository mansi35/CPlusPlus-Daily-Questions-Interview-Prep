class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 and j == n-1)
                    dp[i][j] = grid[i][j];
                else if (i == m-1)
                    dp[i][j] = grid[i][j] + dp[i][j+1];
                else if (j == n-1)
                    dp[i][j] = grid[i][j] + dp[i+1][j];
                else
                    dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};
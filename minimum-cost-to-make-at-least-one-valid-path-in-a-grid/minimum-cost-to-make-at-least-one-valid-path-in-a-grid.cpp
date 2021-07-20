class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return (x >= 0 and x < m and y >= 0 and y < n);
    }
    
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[105][105];
        memset(dp, 1000000, sizeof(dp));
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        dp[0][0] = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            int x = current.first;
            int y = current.second;
            for (int i = 0; i < 4; i++) {
                int X = x + dir[i].first;
                int Y = y + dir[i].second;
                if (isValid(X, Y, m, n)) {
                    if (i + 1 == grid[x][y] and dp[X][Y] > dp[x][y]) {
                        dp[X][Y] = dp[x][y];
                        q.push({X, Y});
                    } else if (dp[X][Y] > dp[x][y] + 1) {
                        dp[X][Y] = dp[x][y] + 1;
                        q.push({X, Y});
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};
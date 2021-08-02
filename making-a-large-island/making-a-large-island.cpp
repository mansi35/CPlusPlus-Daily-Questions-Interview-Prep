class Solution {
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int dfs(vector<vector<int>>& grid,int i,int j, int islandId){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
            return 0;
        grid[i][j] = islandId;
        int down = dfs(grid, i+1, j, islandId);
        int up = dfs(grid, i-1, j, islandId);
        int right = dfs(grid, i, j+1, islandId);
        int left = dfs(grid, i, j-1, islandId);
        return left + right + up + down + 1;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        int m = grid.size(), n = grid[0].size(), maxSize = 0, islandId = 2;
        unordered_map<int, int> landFreq;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, islandId);
                    maxSize = max(maxSize, size);
                    landFreq[islandId++] = size;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uset;
                    for (auto dir: dirs) {
                        int x = dir[0] + i;
                        int y = dir[1] + j;
                        if (x > -1 && y > -1 && x < m && y < n && grid[x][y] != 0) {
                            uset.insert(grid[x][y]);
                        }
                    }
                    
                    int sum = 1;
                    for (int num: uset) {
                        sum += landFreq[num];
                    }
                    
                    maxSize = max(maxSize, sum);
                }
            }
        }
        return maxSize;
    }
};
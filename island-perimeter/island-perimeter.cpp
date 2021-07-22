class Solution {
    vector<int> dx = { 0, -1, 0, 1 };
    vector<int> dy = { 1, 0, -1, 0 };
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& perimeter) {
        if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] == 0) {
            perimeter += 1;
            return;   
        }
        if (grid[i][j] == -1)
            return;
        
        grid[i][j] = -1;
        for (int k = 0; k < 4; k++) {
            dfs(grid, i + dx[k], j + dy[k], perimeter);
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, perimeter);
                }
            }
            
        }
        return perimeter;
    }
};
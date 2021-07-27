class Solution {
    vector<int> dx = { 0, 1, -1, 0 };
    vector<int> dy = { 1, 0, 0, -1 };
public:
    bool isValid(int x, int y, int m, int n) {
        return (x >= 0 and x < m and y >= 0 and y < n);
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> visited(m, vector<int>(n, -1));
        q.push({0, 0, 0, k});
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int x = node[0];
            int y = node[1];
            int currentDist = node[2];
            int kRemaining = node[3];
            
            if(x == m-1 and y == n-1)
                return currentDist;
            
            if(grid[x][y] == 1){
                if(kRemaining > 0)
                    kRemaining--;
                else
                    continue;
            }
            
            if (visited[x][y] != -1 and visited[x][y] >= kRemaining)
                continue;
            
            visited[x][y] = kRemaining;
            
            for (int k = 0; k < 4; k++) {
                if (isValid(x + dx[k], y + dy[k], m, n))
                    q.push({ x + dx[k], y + dy[k], currentDist + 1, kRemaining });
            }
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> rowNum = {-1, 0, 0, 1, 1, 1, -1, -1};
    vector<int> colNum = {0, 1, -1, 0, 1, -1, -1, 1};
    
    bool isValid(int row, int col, int m, int n) {
        return (row >= 0) && (col >= 0) && (row < m) && (col < n);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        queue<pair<int, int>> q;
        map<pair<int, int>, int> dist;
        bool visited[grid.size()][grid[0].size()];
        memset(visited, false, sizeof(visited));
        
        pair<int, int> src = make_pair(0, 0);
        pair<int, int> dest = make_pair(grid.size()-1, grid[0].size()-1);
        
        q.push(src);
        dist[src] = 1;
        
        while (!q.empty()) {
            auto node = q.front();
            
            if (node.first == dest.first && node.second == dest.second) 
                return dist[node];
            
            q.pop();
            for (int i = 0; i < 8; i++) {
                int row = node.first + rowNum[i];
                int col = node.second + colNum[i];
                if (isValid(row, col, grid.size(), grid[0].size()) && grid[row][col] == 0 && !visited[row][col]) {
                    visited[row][col] = true;
                    dist[make_pair(row, col)] = dist[node] + 1;
                    q.push(make_pair(row, col));
                }
            }
        }
        return -1;
    }
};
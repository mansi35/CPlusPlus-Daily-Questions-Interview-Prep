class Solution {
public:
    bool visited[201];
    
    void dfs(vector<vector<int>>& isConnected, int province) {
        visited[province] = true;
        
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[province][i] == 1 && !visited[i])
                dfs(isConnected, i);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        memset(visited, false, sizeof(visited));
        int provinces = 0;
        
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                dfs(isConnected, i);
                provinces++;
            }
        }
        return provinces;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> umap;
        vector<int> result;
        for (auto edge: prerequisites) {
            umap[edge[1]].push_back(edge[0]);
        }
        vector<int> indegree(numCourses, 0);
        
        for (auto list: umap) {
            for (int i: list.second) {
                indegree[i]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            result.push_back(node);
            q.pop();
            for (auto nbr: umap[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        if (result.size() != numCourses) {
            result.clear();  
            return result;
        }
        return result;
    }
};
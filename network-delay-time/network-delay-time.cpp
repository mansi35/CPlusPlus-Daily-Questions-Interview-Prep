class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> umap;
        for (auto time: times) {
            umap[time[0]].push_back({ time[1], time[2] });
        }
        unordered_map<int, int> dist;
        for (int i = 1; i <= n; i++) {
            dist[i] = INT_MAX;
        }
        dist[k] = 0;
        set<pair<int, int>> s;
        s.insert({ dist[k], k });
        
        while (!s.empty()) {
            auto p = *(s.begin());
            int nodeDist = p.first;
            int node = p.second;
            s.erase(s.begin());
            
            for (auto nbr: umap[node]) {
                if (nodeDist + nbr.second < dist[nbr.first]) {
                    int dest = nbr.first;
                    auto nodeToUpdate = s.find({ dist[dest], dest });
                    if (nodeToUpdate != s.end()) {
                        s.erase(nodeToUpdate);
                    }
                    dist[dest] = nodeDist + nbr.second;
                    s.insert({ dist[dest], dest });
                }
            }
        }
        int networkDelayTime = INT_MIN;
         for (auto d: dist) {
             if (d.second == INT_MAX)
                 return -1;
             networkDelayTime = max(networkDelayTime, d.second);
         }
        return networkDelayTime;
    }
};
class DSU {
    int *parent;
    int *rank;
public:
    
    DSU (int V) {
        parent = new int[V];
        rank = new int[V];
        for (int i = 0; i < V; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    
    int find(int coordinate) {
        if (parent[coordinate] == -1) {
            return coordinate;
        }
        return parent[coordinate] = find(parent[coordinate]);
    }
    
    void unite(int coordinate1, int coordinate2) {
        auto s1 = find(coordinate1);
        auto s2 = find(coordinate2);
        
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Solution {
    public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() <= 1)
            return 0;
        DSU s(points.size());
        vector<vector<int>> edges;
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({ cost, i, j });
            }
        }
        
        sort(edges.begin(), edges.end());
        
        int ans = 0;
        for (auto edge: edges) {
            int w = edge[0];
            auto coordinate1 = edge[1];
            auto coordinate2 = edge[2];
            
            if (s.find(coordinate1) != s.find(coordinate2)) {
                s.unite(coordinate1, coordinate2);
                ans += w;
            }
        }
        return ans;
    }
};
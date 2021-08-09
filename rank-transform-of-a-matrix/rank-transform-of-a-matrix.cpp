class UnionFind {
public:
    unordered_map<int, int> parent;
    int Find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = Find(parent[u]);
    }
    void Union(int u, int v) {
        if (parent.count(u) == 0) parent[u] = u;
        if (parent.count(v) == 0) parent[v] = v;
        int pu = Find(u), pv = Find(v);
        if (pu != pv) parent[pu] = pv;
    }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        map<int, vector<pair<int, int>>> groupByValue;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                groupByValue[matrix[r][c]].push_back({r, c});

        vector<int> rank(m+n, 0); // rank[i] is the largest rank of the row or column so far
        for (auto const& [_, cells]  : groupByValue) {
            UnionFind uf;
            for (auto const& [r, c] : cells)
                uf.Union(r, c + m);  // Union row `r` with column `c` (column +m to separate with r)

            unordered_map<int, vector<int>> groups;
            for (auto const& [u, _] : uf.parent) {
                groups[uf.Find(u)].push_back(u);
            }

            for (auto const& [_, group] : groups) {
                int maxRank = 0;
                for (int i : group) maxRank = max(maxRank, rank[i]); // Get max rank of all included rows and columns
                for (int i : group) rank[i] = maxRank + 1;  // Update all rows or columns in the same groups to new rank
            }
            for (auto const& [r, c] : cells) matrix[r][c] = rank[r];  // or matrix[r][c] = rank[c], both are correct.
        }
        return matrix;
    }
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> umap;
        vector<double> result;
        for (int i = 0; i < equations.size(); i++) {
            umap[equations[i][0]].push_back({ equations[i][1], values[i] });
            umap[equations[i][1]].push_back({ equations[i][0], 1 / values[i] });
        }
        for (int i = 0; i < queries.size(); i++) {
            unordered_map<string, bool> visited;
            queue<string> q;
            unordered_map<string, double> ans;
            for (auto node: umap) {
                ans[node.first] = 1;
            }
            string src = queries[i][0];
            string dest = queries[i][1];
            visited[src] = true;
            q.push(src);
            bool flag = false;
            while (!q.empty() and !flag and src != dest) {
                string var = q.front();
                q.pop();
                for (auto nbr: umap[var]) {
                    if (nbr.first == dest) {
                        flag = true;
                        ans[nbr.first] = ans[var] * nbr.second;
                        break;
                    }
                    if (!visited[nbr.first]) {
                        ans[nbr.first] = ans[var] * nbr.second;
                        visited[nbr.first] = true;
                        q.push(nbr.first);
                    }
                }
            }
            if (!flag)
                ans[dest] = -1;
            if (umap.count(src) and src == dest)
                ans[dest] = 1;
            result.push_back(ans[dest]);
        }
        return result;
    }
};
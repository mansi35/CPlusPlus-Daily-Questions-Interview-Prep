class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> umap(26, 0);
        for (int i = 0; i < tasks.size(); i++) {
            umap[tasks[i] - 'A']++;
        }
        sort(umap.begin(), umap.end());
        int maxValue = umap[25] - 1;
        int idleSlots = maxValue * n;
        
        for (int i = 24; i >= 0; i--) {
            idleSlots -= min(umap[i], maxValue);
        }
        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }
};
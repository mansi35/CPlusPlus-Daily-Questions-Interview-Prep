class Solution {
public:
    struct customCompare {
        bool operator()(pair<int, string> const& p1, pair<int, string> const& p2) {
            if (p1.first == p2.first)
                return p1.second > p2.second;
            return p1.first < p2.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> umap;
        for (int i = 0; i < words.size(); i++) {
            umap[words[i]] += 1;
        }
        vector<string> result;
        priority_queue<pair<int, string>, vector<pair<int, string>>, customCompare> pq;
        for (auto word: umap) {
            pq.push({ word.second, word.first });
        }
        while (k--) {
            string word = pq.top().second;
            pq.pop();
            result.push_back(word);
        }
        return result;
    }
};
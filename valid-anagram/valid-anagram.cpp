class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;
        for (int i = 0; i < s.size(); i++) {
            umap[s[i]] += 1;
        }
        char found;
        for (int i = 0; i < t.size(); i++) {
            umap[t[i]] -= 1;
        }
        for (auto u: umap) {
            if (u.second != 0)
                return false;
        }
        return true;
    }
};
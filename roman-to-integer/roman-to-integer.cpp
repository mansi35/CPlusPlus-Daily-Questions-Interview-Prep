class Solution {
    unordered_map<char, int> umap =
    {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
public:
    int romanToInt(string s) {
        int ans = 0;
        ans += umap[s[s.length() - 1]];
        for (int i = s.length() - 2; i >= 0; i--) {
            if (umap[s[i]] < umap[s[i+1]])
                ans -= umap[s[i]];
            else
                ans += umap[s[i]];
        }
        return ans;
    }
};
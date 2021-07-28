class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (auto i : strs) {
            string word = i;
            sort(word.begin(), word.end());
            anagrams[word].push_back(i);
        }
        
        vector<vector<string>> result;
        for (auto i : anagrams) {
            result.push_back(i.second);
        }
        return result;
    }
};
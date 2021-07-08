class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        vector<string> words;
        for (auto i : strs) {
            string word = i;
            sort(word.begin(), word.end());
            
            if (anagrams[word].size() == 0)
                words.push_back(word);
            anagrams[word].push_back(i);
        }
        
        vector<vector<string>> result;
        for (auto i : words) {
            result.push_back(anagrams[i]);
        }
        return result;
    }
};
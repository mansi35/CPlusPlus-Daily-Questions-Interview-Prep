class Solution {
public:
    
    void letterCasePermutationHelper(string s, vector<string> &allPerms, int i) {
        if (i > s.length())
            return;
        if (find(allPerms.begin(), allPerms.end(), s) == allPerms.end()) {
            allPerms.push_back(s);
        }
        if (i+1 <= s.length()) {
            s[i] = tolower(s[i]);
            letterCasePermutationHelper(s, allPerms, i+1);
            s[i] = toupper(s[i]);
            letterCasePermutationHelper(s, allPerms, i+1);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> allPermutations;
        letterCasePermutationHelper(s, allPermutations, 0);
        return allPermutations;
    }
};
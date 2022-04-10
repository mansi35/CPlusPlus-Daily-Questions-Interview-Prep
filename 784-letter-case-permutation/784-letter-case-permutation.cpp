class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> allPerms;
        letterCasePermutationHelper(s, allPerms, 0);
        return allPerms;
    }
    
    void letterCasePermutationHelper(string s, vector<string> &allPerms, int i) {
        if (i == s.length()) {
            allPerms.push_back(s);
            return;
        }
        if (isdigit(s[i])) {
            letterCasePermutationHelper(s, allPerms, i+1);
        } else {
            s[i] = tolower(s[i]);
            letterCasePermutationHelper(s, allPerms, i+1);
            s[i] = toupper(s[i]);
            letterCasePermutationHelper(s, allPerms, i+1);
        }
    }
};
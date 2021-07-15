class Solution {
public:    
    vector<string> letterCasePermutation(string s) {
        vector<string> allPermutations;
        letterCasePermutationHelper(s, allPermutations, 0);
        return allPermutations;
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
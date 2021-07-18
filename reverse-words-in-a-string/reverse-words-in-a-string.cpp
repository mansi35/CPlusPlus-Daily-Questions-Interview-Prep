class Solution {
public:
    string reverseWords(string s) {
        string subStr;
        vector<string> ans;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (subStr.length() != 0)
                    ans.push_back(subStr);
                subStr = "";
            } else {
                subStr += s[i];
            }
        }
        if (subStr.length() != 0)
            ans.push_back(subStr);
        
        string rev;
        for (int i = 0; i < ans.size(); i++) {
            rev = ans[i] + " " + rev;
        }
        rev.pop_back();
        return rev;
    }
};
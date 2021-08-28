class Solution {
public:
    bool isSubsequence(string str,string s) {
        int j = 0;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == str[j])
                j++;
            if (j == str.length())
                break;
        }
        return j == str.length();
    }
    
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](string& a, string& b) {
           return a.length() > b.length();
        });
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < strs.size() and strs[j].length() >= strs[i].length(); j++) {
                if(i != j and isSubsequence(strs[i], strs[j]))
                    goto h;
            }
            return strs[i].length();
            h:;
        }
        return -1;
    }
};
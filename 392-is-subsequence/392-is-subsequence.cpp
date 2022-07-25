class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0)
            return true;
        int index = 0;
        for (int i = 0; i < t.length(); i++) {
            if (s[index] == t[i])
                index++;
        }
        return index == s.length();
    }
};
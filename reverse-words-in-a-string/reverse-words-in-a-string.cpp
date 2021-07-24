class Solution {
public:
    string reverseWords(string s) {
        string subStr, result;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (subStr.length() != 0)
                    result = subStr + " " + result;
                subStr = "";
            } else {
                subStr += s[i];
            }
        }
        if (subStr.length() != 0)
            result = subStr + " " + result;
        
        result.pop_back();
        return result;
    }
};
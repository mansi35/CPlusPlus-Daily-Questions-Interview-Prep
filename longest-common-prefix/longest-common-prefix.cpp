class Solution {
public:
    string commonPrefix(string string1, string string2) {
        int i = 0, j = 0;
        string prefix;
        while (i < string1.length() and j < string2.length()) {
            if (string1[i] == string2[i]) {
                prefix += string1[i];
                i++;
                j++;
            } else {
                break;
            }
        }
        return prefix;
    }
    
    string longestCommonPrefixHelper(vector<string>& strs, int start, int end) {
        if (start == end) {
            return strs[start];
        }
        int mid = (start + end) / 2;
        string string1 = longestCommonPrefixHelper(strs, start, mid);
        string string2 = longestCommonPrefixHelper(strs, mid + 1, end);
        return commonPrefix(string1, string2);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        return longestCommonPrefixHelper(strs, 0, strs.size() - 1);
    }
};
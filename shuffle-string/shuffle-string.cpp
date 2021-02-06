class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result(s.length(), '*');
        int size = indices.size();
        for (int i = 0; i < size; i++) {
            result[indices[i]] = s[i];
        }
        return result;
    }
};

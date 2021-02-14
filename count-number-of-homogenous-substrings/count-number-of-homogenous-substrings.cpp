class Solution {
public:
    int countHomogenous(string s) {
        const unsigned int M = 1000000007;
        int n = s.length();
        vector<string> splitString;
        int homogenousCount = 0;
        string temp = "";
        temp += s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1]) {
                splitString.push_back(temp);
                temp = "";
            }
            temp += s[i];
        }
        splitString.push_back(temp);
        for (int i = 0; i < splitString.size(); i++) {
            homogenousCount += (splitString[i].length() * (splitString[i].length() + 1) / 2) % M;
        }
        return homogenousCount;
    }
};

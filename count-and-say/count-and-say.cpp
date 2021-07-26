class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string prev = countAndSay(n-1);
        int cnt = 1, i;
        string res;
        for (i = 1; i < prev.length(); i++) {
            if (prev[i] == prev[i-1])
                cnt++;
            else {
                res += to_string(cnt) + prev[i-1];
                cnt = 1;
            }
        }
        res += to_string(cnt) + prev[i-1];
        return res;
    }
};
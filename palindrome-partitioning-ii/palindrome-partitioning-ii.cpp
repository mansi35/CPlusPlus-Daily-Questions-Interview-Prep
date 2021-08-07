class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
            }
        }
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if ((j-i) >= 2 && s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                }
            }
        }
        
        int cuts[n];
    
        for (int i = 0; i < n; i++) {
            int temp = INT_MAX;
            if (dp[0][i]) {
                cuts[i] = 0;
            } else {
                for (int j = 0; j < i; j++) {
                    if (dp[j+1][i] && temp > cuts[j] + 1) {
                        temp = cuts[j] + 1;
                    }
                }
                cuts[i] = temp;
            }
        }
        return cuts[n-1];
    }
};
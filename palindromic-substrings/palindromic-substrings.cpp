class Solution {
public:
    int dp[1002][1002];
    bool isPalindrome(string s, int i, int j) {
        if (i >= j)
            return true;
        if (dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = (s[i] == s[j] and isPalindrome(s, i+1, j-1));
    }
    
    int countSubstrings(string s) {
        memset(dp, -1, sizeof(dp));
        int count = 0;
        for(int i = 0; i < s.length(); i++)
            for(int j = i; j < s.length(); j++)
                if(isPalindrome(s, i, j))
                    count++;
        return count;
    }
};
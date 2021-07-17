class Solution {
public:
    int fibHelper(int n, vector<int>& dp) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (dp[n] != 0)
            return dp[n];
        return dp[n] = fibHelper(n-1, dp) + fibHelper(n-2, dp);
    }
    
    int fib(int n) {
        vector<int> dp(n+1, 0);
        return fibHelper(n, dp);
    }
};
class Solution {
    vector<int> dp = vector<int>(1000005, INT_MIN);
public:
    int numberOfSteps (int num) {
        if (num == 0)
            return 0;
        if (dp[num] != INT_MIN)
            return dp[num];
        if (num % 2 == 0) {
            return dp[num] = 1 + numberOfSteps(num/2);
        }
        else {
            return dp[num] = 1 + numberOfSteps(num-1);
        }
    }
};
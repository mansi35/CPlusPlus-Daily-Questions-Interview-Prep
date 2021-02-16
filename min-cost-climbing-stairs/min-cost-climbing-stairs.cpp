class Solution {
public:
    int minCost(vector<int>& cost, int stepIndex, vector<int>& dp) {
        if (stepIndex >= cost.size())
            return 0;
        if (dp[stepIndex] == -1)
            dp[stepIndex] = cost[stepIndex] + min(minCost(cost, stepIndex+1, dp), minCost(cost, stepIndex+2, dp));
        return dp[stepIndex];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(minCost(cost, 0, dp), minCost(cost, 1, dp));
    }
};
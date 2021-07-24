class Solution {
public:
    int memo[50001];
    int findMaxProfit(vector<vector<int>>& jobs, vector<int>& start, int n, int position) {
        if (position == n) {
            return 0;
        }
        
        if (memo[position] != -1) {
            return memo[position];
        }
        
        int nextIndex = lower_bound(start.begin(), start.end(), jobs[position][1]) - start.begin();
        int maxProfit = max(findMaxProfit(jobs, start, n, position+1), jobs[position][2] + findMaxProfit(jobs, start, n, nextIndex));
        return memo[position] = maxProfit;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        memset(memo, -1, sizeof(memo));
        
        for (int i = 0; i < profit.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        for (int i = 0; i < profit.size(); i++) {
            startTime[i] = jobs[i][0];
        }
        return findMaxProfit(jobs, startTime, profit.size(), 0);
    }
};
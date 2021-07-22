class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end());
        
        int count = 0;
        int pre = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < pre) {
                count++;
                pre = min(pre, intervals[i][1]);
            } else {
                pre = intervals[i][1];
            }
        }
        return count;
    }
};
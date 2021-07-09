class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int onesTillNow = 0, maxOnesTillNow = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                onesTillNow += 1;
            else {
                maxOnesTillNow = max(onesTillNow, maxOnesTillNow);
                onesTillNow = 0;
            }
        }
        return maxOnesTillNow = max(onesTillNow, maxOnesTillNow);
    }
};
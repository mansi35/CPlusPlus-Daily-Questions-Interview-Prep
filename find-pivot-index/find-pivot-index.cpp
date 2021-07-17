class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefixSum;
        prefixSum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            prefixSum.push_back(nums[i] + prefixSum[i-1]);
        }
        for (int i = 0; i < prefixSum.size(); i++) {
            if (prefixSum[i] - nums[i] == prefixSum[prefixSum.size()-1] - prefixSum[i])
                return i;
        }
        return -1;
    }
};
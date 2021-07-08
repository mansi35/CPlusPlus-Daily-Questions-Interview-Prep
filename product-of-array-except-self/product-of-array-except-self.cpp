class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre = 1, suf = 1;
        vector<int> ans(nums.size(), 1);
        for (int i = 0; i < nums.size()-1; i++) {
            pre *= nums[i];
            suf *= nums[nums.size()-1-i];
            ans[i+1] *= pre;
            ans[nums.size()-i-2] *= suf;
        }
        return ans;
    }
};
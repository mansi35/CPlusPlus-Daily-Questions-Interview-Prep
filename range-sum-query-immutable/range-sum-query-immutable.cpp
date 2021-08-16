class NumArray {
    vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        preSum.clear();
        preSum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            preSum.push_back(nums[i] + preSum[i-1]);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0)
            return preSum[right];
        return preSum[right] - preSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
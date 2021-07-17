class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> pair;
        int left = 0, right = nums.size()-1;
        while (left < right) {
            if (left != 0 and nums[left] == nums[left-1]) {
                left++;
                continue;
            }
            int sum = nums[left] + nums[right];
            if (sum == target) {
                pair.push_back(left+1);
                pair.push_back(right+1);
                return pair;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return pair;
    }
};
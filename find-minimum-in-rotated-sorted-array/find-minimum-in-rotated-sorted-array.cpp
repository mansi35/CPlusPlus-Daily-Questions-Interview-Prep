class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int start = 0, end = nums.size() - 1;
        if (nums[end] > nums[start]) {
            return nums[start];
        }
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            if (nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }
            if (nums[end] > nums[mid])
                end = mid - 1;
            else
                start = mid+1;
        }
        return -1;
    }
};
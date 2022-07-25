class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int i = 0, j = nums.size()-1;
        int index = j;
        while (i <= j) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                result[index] = nums[j] * nums[j];
                j--;
            } else {
                result[index] = nums[i] * nums[i];
                i++;
            }
            index--;
        }
        return result;
    }
};
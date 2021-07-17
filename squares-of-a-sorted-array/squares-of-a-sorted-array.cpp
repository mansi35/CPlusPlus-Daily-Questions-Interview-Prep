class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int i = 0, j = nums.size()-1;
        int index = j;
        while (i <= j) {
            int val1 = nums[i] * nums[i];
            int val2 = nums[j] * nums[j];
            if (val1 < val2) {
                result[index] = val2;
                j--;
            } else {
                result[index] = val1;
                i++;
            }
            index--;
        }
        return result;
    }
};
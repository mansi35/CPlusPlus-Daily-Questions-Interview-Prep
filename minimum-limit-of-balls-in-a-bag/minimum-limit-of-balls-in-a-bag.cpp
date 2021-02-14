class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = 0;
        for (auto num: nums) {
            right = max(right, num);
        }
        while (left < right) {
            int mid = (left + right) / 2, operations = 0;
            for (int num : nums)
                operations += (num - 1) / mid;
            if (operations > maxOperations)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
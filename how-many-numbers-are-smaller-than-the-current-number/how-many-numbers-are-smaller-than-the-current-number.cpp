class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0);
        for (int num: nums) {
            count[num]++;
        }
        int c = 0;
        for (int i = 0; i < 101; i++) {
            if (count[i]) {
                int total = count[i];
                count[i] = c;
                c = c + total;
            }
        }
        vector<int> result(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            result[i] = count[nums[i]];
        }
        return result;
    }
};
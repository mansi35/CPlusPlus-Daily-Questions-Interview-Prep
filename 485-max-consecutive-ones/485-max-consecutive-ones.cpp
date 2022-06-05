class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsOnes = 0, consOnes = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                consOnes += 1;
            else {
                maxConsOnes = max(maxConsOnes, consOnes);
                consOnes = 0;
            }
        }
        return max(maxConsOnes, consOnes);
    }
};
class Solution {
public:
    vector<vector<int>> twoSum(vector<int> nums, int start, int end, int target) {
        vector<vector<int>> pairs;
        int left = start, right = end;
        while (left < right) {
            if (left != start and nums[left] == nums[left-1]) {
                left++;
                continue;
            }
            int sum = nums[left] + nums[right];
            if (sum == target) {
                vector<int> pair;
                pair.push_back(nums[left]);
                pair.push_back(nums[right]);
                pairs.push_back(pair);
                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return pairs;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        int n = nums.size();
        if (n < 3)
            return triplets;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i <= n-3; i++) {
            if (i != 0 and nums[i] == nums[i-1])
                continue;
            int target = 0 - nums[i];
            vector<vector<int>> pairs = twoSum(nums, i+1, n-1, target);
            for (auto pair: pairs) {
                pair.push_back(nums[i]);
                triplets.push_back(pair);
            }
        }
        return triplets;
    }
};
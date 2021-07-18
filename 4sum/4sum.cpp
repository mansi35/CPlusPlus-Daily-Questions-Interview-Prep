class Solution {
public:
    vector<vector<int>> twoSum(vector<int> nums, int target, int start) {
        vector<vector<int>> pairs;
        int left = start, right = nums.size() - 1;;
        while (left < right) {
            if (left != start and nums[left] == nums[left-1]) {
                left++;
                continue;
            }
            int sum = nums[left] + nums[right];
            if (sum == target) {
                pairs.push_back({ nums[left], nums[right] });
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
    
    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
        vector<vector<int>> res;
        if (start == nums.size() or nums[start] * k > target or target > nums.back() * k)
            return res;
        if (k == 2)
            return twoSum(nums, target, start);
        for (int i = start; i < nums.size(); i++) {
            if (i != start and nums[i - 1] == nums[i]) 
                continue;
            for (auto elements : kSum(nums, target - nums[i], i + 1, k - 1)) {
                elements.push_back(nums[i]);
                res.push_back(elements);
            }
        }
        return res;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }
};
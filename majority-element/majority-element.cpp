class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        int maxElement = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            umap[nums[i]] += 1;
            if (umap[nums[i]] > n/2)
                maxElement = nums[i];
        }
        return maxElement;
    }
};
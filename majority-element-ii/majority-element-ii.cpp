class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        vector<int> majority;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (umap[nums[i]] > n/3)
                continue;
            umap[nums[i]] += 1;
            if (umap[nums[i]] > n/3) {
                majority.push_back(nums[i]);
            }
        }
        
        return majority;
    }
};
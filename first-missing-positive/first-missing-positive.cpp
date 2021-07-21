class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]] = 1;
        }
        for (int i = 1; i <= nums.size()+1; i++) {
            if (umap[i] == 0)
                return i;
        }
        return -1;
    }
};
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]] += 1;
        }
        int goodPairs = 0;
        for (auto ele: umap) {
            goodPairs += ele.second * (ele.second - 1) / 2;
        }
        return goodPairs;
    }
};
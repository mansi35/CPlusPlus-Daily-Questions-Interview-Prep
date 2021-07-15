class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, bool> umap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]] = true;
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (!umap[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
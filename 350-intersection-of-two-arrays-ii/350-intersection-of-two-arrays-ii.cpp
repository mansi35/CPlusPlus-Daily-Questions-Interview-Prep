class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        vector<int> result;
        
        for (int i = 0; i < nums1.size(); i++) {
            umap[nums1[i]] += 1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (umap[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                umap[nums2[i]] -= 1;
            }
        }
        return result;
    }
};
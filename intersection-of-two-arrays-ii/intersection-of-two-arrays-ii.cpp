class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> set;
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
           set.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            if(set.count(nums2[i])) {
                result.push_back(nums2[i]);
                set.erase(set.find(nums2[i]));
            }
        }
        return result;
    }
};
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int,int> mp;
        for (int d: nums4) {
            for (int c: nums3) {
                mp[d+c]++;
            }
        }
        for (int a: nums1) {
            for(int b: nums2) {
                int sum = a+b;
                if(mp[-1*sum] != 0)
                    count += mp[-1*sum];
            }
        }
        return count;
    }
};
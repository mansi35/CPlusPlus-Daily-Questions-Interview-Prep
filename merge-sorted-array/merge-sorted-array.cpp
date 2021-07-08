class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size1 = m-1;
        int size2 = n-1;
        int size = n+m-1;
        while(size1 >= 0 && size2 >= 0) {
            nums1[size--] = (nums1[size1] > nums2[size2])? nums1[size1--]: nums2[size2--];
        }
        copy_n(nums2.begin(), size2+1, nums1.begin());
    }
};
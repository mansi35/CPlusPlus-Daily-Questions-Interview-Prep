class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX, right = INT_MAX;
        for (int n: nums) {
            if (n <= left) 
                left = n;
            else if (n <= right) 
                right = n;
            else
                return true;
        }
        return false;
    }
};
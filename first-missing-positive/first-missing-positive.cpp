class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size()+1; i++) {
            if(s.find(i) == s.end())
                return i;
        }
        return -1;
    }
};
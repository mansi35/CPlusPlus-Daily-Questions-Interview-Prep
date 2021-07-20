class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        int prev = *(s.begin());
        s.erase(s.begin());
        int res = 1, finalResult = 1;
        while (!s.empty()) {
            if (*(s.begin()) == prev + 1) {
                prev = *(s.begin());
                res++;
            } else {
                finalResult = max(finalResult, res);
                cout << finalResult << endl;
                res = 1;
                prev = *(s.begin());
            }
            s.erase(s.begin());
        }
        finalResult = max(finalResult, res);
        return finalResult;
    }
};
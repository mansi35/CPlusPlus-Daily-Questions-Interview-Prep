class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0)
            return m * n;
        int first = INT_MAX, second = INT_MAX;
        for (auto op: ops) {
            first = min(first, op[0]);
            second = min(second, op[1]);
        }
        return first * second;
    }
};
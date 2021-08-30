class Solution {
public:
    static bool compare1(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    
    static bool compare2(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0)
            return m * n;
        sort(ops.begin(), ops.end(), compare1);
        int first = ops[0][0];
        sort(ops.begin(), ops.end(), compare2);
        int second = ops[0][1];
        return first * second;
    }
};
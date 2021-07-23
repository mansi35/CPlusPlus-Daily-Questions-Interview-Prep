class Solution {
public:
    bitset<9> col, d1, d2;
    
    void solveNQueensHelper(vector<string>& rows, vector<vector<string>>& result, int n, int i) {
        if ( i == n) {
            result.push_back(rows);
            return;
        }
        for (int pos = 0; pos < n; pos++) {
            if (!col[pos] and !d1[i-pos+n-1] and !d2[i+pos]) {
                col[pos] = d1[i-pos+n-1] = d2[i+pos] = 1;
                rows[i][pos] = 'Q';
                solveNQueensHelper(rows, result, n, i+1);
                rows[i][pos] = '.';
                col[pos] = d1[i-pos+n-1] = d2[i+pos] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> rows(n, string(n, '.'));
        solveNQueensHelper(rows, result, n, 0);
        return result;
    }
};

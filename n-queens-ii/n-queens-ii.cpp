class Solution {
public:
    bitset<9> col, d1, d2;
    
    void solveNQueensHelper(int& result, int n, int r) {
        if ( r == n) {
            result += 1;
            return;
        }
        for (int c = 0; c < n; c++) {
            if (!col[c] and !d1[r-c+n-1] and !d2[r+c]) {
                col[c] = d1[r-c+n-1] = d2[r+c] = 1;
                solveNQueensHelper(result, n, r+1);
                col[c] = d1[r-c+n-1] = d2[r+c] = 0;
            }
        }
    }
    
    int totalNQueens(int n) {
        int result = 0;
        solveNQueensHelper(result, n, 0);
        return result;
    }
};

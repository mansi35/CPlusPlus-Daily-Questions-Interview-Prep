class Solution {
public:
    bool canPlace(vector<string> rows, int n, int i, int j) {
        for(int row = 0; row < n; row++){
            if(rows[row][j] == 'Q'){
                return false;
            }
        }
        int x = i;
        int y = j;
        while (x >= 0 && y >= 0) {
            if (rows[x][y] == 'Q') {
                return false;
            }
            x--;
            y--;
        }
        x = i;
        y = j;
        while (x >= 0 && y < n) {
            if (rows[x][y] == 'Q') {
                return false;
            }
            x--;
            y++;
        }
        return true;
    }
    
    void solveNQueensHelper(vector<string>& rows, int& result, int n, int i) {
        if ( i == n) {
            result += 1;
            return;
        }
        for (int pos = 0; pos < n; pos++) {
            if (canPlace(rows, n, i, pos)) {
                rows[i][pos] = 'Q';
                solveNQueensHelper(rows, result, n, i+1);
                rows[i][pos] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        int result = 0;
        vector<string> rows(n, string(n, '.'));
        solveNQueensHelper(rows, result, n, 0);
        return result;
    }
};
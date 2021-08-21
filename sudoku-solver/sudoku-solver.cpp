class Solution {
public:
    bool canPlace(vector<vector<char>>& board, int i, int j, char num) {
        for (int x = 0; x < 9; x++) {
            if (board[x][j] == num)
                return false;
            if (board[i][x] == num)
                return false;
        }
        int rn = sqrt(9);
        int sx = (i / rn) * rn;
        int sy = (j / rn) * rn;
        
        for (int x = sx; x < sx + rn; x++) {
            for (int y = sy; y < sy + rn; y++) {
                if (board[x][y] == num)
                    return false;
            }
        }
        return true;
    }
    
    bool solveSudokuHelper(vector<vector<char>>& board, int i, int j) {
        if (i == 9) {
            return true;
        }
        
        if (j == 9) {
            return solveSudokuHelper(board, i+1, 0);
        }
        
        if (board[i][j] != '.') {
            return solveSudokuHelper(board, i, j+1);
        }
        
        for (int num = 1; num <= 9; num++) {
            if (canPlace(board, i, j, num + '0')) {
                board[i][j] = num + '0';
                if (solveSudokuHelper(board, i, j+1))
                    return true;
            }
        }
        board[i][j] = '.';
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board, 0, 0);
    }
};
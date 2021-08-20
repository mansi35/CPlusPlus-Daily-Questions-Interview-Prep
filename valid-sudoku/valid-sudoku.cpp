class Solution {
public:
    bool canPlace(vector<vector<char>>& board, int i, int j, char num) {
        for (int x = 0; x < 9; x++) {
            if (board[x][j] == num && x != i)
                return false;
            if (board[i][x] == num && x != j)
                return false;
        }
        int rn = sqrt(9);
        int sx = (i / rn) * rn;
        int sy = (j / rn) * rn;
        
        for (int x = sx; x < sx + rn; x++) {
            for (int y = sy; y < sy + rn; y++) {
                if (board[x][y] == num && x != i && y != j)
                    return false;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (isdigit(board[i][j]) && !canPlace(board, i, j, board[i][j]))
                    return false;
            }
        }
        return true;
    }
};
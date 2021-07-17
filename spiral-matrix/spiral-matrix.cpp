class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        if (r == 0)
            return vector<int>();
        int c = matrix[0].size();
        vector<int> spiral;
        int startRow = 0, startCol = 0, endRow = r-1, endCol = c-1;
        while (startRow <= endRow and startCol <= endCol)
        {
            for (int j = startCol; j <= endCol; j++) {
                spiral.push_back(matrix[startRow][j]);
            }
            startRow++;
            
            for (int i = startRow; i <= endRow; i++) {
                spiral.push_back(matrix[i][endCol]);
            }
            endCol--;
            
            if (endRow >= startRow) {
                for (int j = endCol; j >= startCol; j--) {
                    spiral.push_back(matrix[endRow][j]);
                }
                endRow--;
            }
            if (endCol >= startCol) {
                for (int i = endRow; i >= startRow; i--) {
                    spiral.push_back(matrix[i][startCol]);
                }
                startCol++;
            }
        }
        return spiral;
    }
};
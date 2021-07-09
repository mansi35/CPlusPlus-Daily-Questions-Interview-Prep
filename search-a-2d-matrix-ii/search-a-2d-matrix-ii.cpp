class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1;
        int smallest = matrix[0][0], largest = matrix[m - 1][n - 1];
        if (target < smallest or target > largest)
            return false;
        while (i < m and j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (target < matrix[i][j]) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};
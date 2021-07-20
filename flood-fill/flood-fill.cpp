class Solution {
    vector<int> dx = { 0, -1, 0, 1 };
    vector<int> dy = { 1, 0, -1, 0 };
public:
    void floodFillHelper(vector<vector<int>>& image, int i, int j, int prevColor, int newColor) {
        if (i < 0 or i >= image.size() or j < 0 or j >= image[0].size())
            return;
        if (image[i][j] != prevColor)
            return;
        image[i][j] = newColor;
        for (int k = 0; k < 4; k++) {
            floodFillHelper(image, i + dx[k], j + dy[k], prevColor, newColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor)
            floodFillHelper(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};
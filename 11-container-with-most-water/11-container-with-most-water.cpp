class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, maxA = 0;
        while (i < j) {
            if (height[i] > height[j]) {
                maxA = max(maxA, (j-i) * height[j]);
                j--;
            }
            else {
                maxA = max(maxA, (j-i) * height[i]);
                i++;
            }
        }
        return maxA;
    }
};
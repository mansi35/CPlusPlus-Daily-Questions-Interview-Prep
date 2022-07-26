class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty())
        {
            return 0;
        }
        stack<int> s;
        int maxA = 0, n = heights.size();
        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || heights[s.top()] >= heights[i])) {
                int height = heights[s.top()];
                s.pop();
                int width;
                if (s.empty()) width = i;
                else width = i - s.top() - 1;
                maxA = max(maxA, height * width);
            }
            s.push(i);
        }
        return maxA;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty())
        {
            return 0;
        }
        stack<int> histogram;
        int n = heights.size();
        int area = 0;
        histogram.push(0);
        for (int i = 1; i <= n; i++) {
            while (!histogram.empty() and (i == n || heights[i] < heights[histogram.top()])) {
                int top = histogram.top();
                histogram.pop();
                if (histogram.empty())
                    area = max(area, heights[top] * i);
                else
                    area = max(area, heights[top] * (i - histogram.top() - 1));
            }
            histogram.push(i);
        }
        return area;
    }
};
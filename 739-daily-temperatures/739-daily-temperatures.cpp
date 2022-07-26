class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       stack<int> s;
        vector<int> ans(temperatures.size(), 0);
        
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            int todaysTemp = temperatures[i];
            while (!s.empty() && temperatures[s.top()] <= todaysTemp)
                s.pop();
            int warmerDay = s.empty() ? 0 : s.top();
            int span = warmerDay == 0 ? 0 : warmerDay - i;
            ans[i] = span;
            s.push(i);
        }
        
        return ans;
    }
};
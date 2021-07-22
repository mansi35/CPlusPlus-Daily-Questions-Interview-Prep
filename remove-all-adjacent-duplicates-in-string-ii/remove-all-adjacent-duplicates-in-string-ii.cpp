class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stk;
        
        for(auto item : s) {
            if (stk.empty() || stk.top().first != item) {
                stk.push({ item, 1 });
            } else {
                stk.top().second++;
            }
                        
            if (stk.top().second == k) {
                stk.pop();
            }
        }
        
        string result;
        while(!stk.empty()) {
            result.append(stk.top().second, stk.top().first);
            stk.pop();
        }        
        reverse(result.begin(), result.end());
        return result;
    }
};
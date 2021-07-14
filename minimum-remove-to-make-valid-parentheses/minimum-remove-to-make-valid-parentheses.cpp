class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int open = 0, close = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                open++;
            } else if (s[i] == ')') {
                if (close < open) {
                    st.push(s[i]);
                    close++;
                }
            } else {
                st.push(s[i]);
            }
        }
        open = 0;
        close = 0;
        string result;
        while (!st.empty()) {
            if (st.top() == ')') {
                result += st.top();
                st.pop();
                close++;
            } else if (st.top() == '(') {
                if (open < close) {
                    result += st.top();
                    open++;
                }
                st.pop();
            } else {
                result += st.top();
                st.pop();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0, close = 0;
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                open++;
            } else if (s[i] == ')') {
                if (open > close) {
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
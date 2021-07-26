class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        for (int x: pushed) {
            s.push(x);
            while (!s.empty() and j < pushed.size() and s.top() == popped[j]) {
                s.pop();
                j++;
            }
        }
        return j == pushed.size();
    }
};
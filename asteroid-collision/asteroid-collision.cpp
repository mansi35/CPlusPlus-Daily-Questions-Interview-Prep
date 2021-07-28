class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        s.push(asteroids[0]);
        for (int i = 1; i < asteroids.size();) {
            if (s.empty()) {
                s.push(asteroids[i]);
                i++;
            } else if (s.top() > 0 and asteroids[i] < 0) {
                if (abs(s.top()) == abs(asteroids[i])) {
                    s.pop();
                    i++;
                } else if (abs(s.top()) < abs(asteroids[i])) {
                    s.pop();
                } else {
                    i++;
                }
            } else {
                s.push(asteroids[i]);
                i++;
            }
        }
        vector<int> ans(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};
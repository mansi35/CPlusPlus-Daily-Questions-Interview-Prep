class Solution {
public:
    int calPoints(vector<string>& ops) {
        list<int> result;
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "+") {
                result.push_front(*(result.begin()) + *(next(result.begin())));
            } else if (ops[i] == "C") {
                result.pop_front();
            } else if (ops[i] == "D") {
                result.push_front(2 * *(result.begin()));
            } else {
                result.push_front(stoi(ops[i]));
            }
        }
        int ans = accumulate(result.begin(), result.end(), 0);
        return ans;
    }
};
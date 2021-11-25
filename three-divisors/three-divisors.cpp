class Solution {
public:
    bool isThree(int n) {
        unordered_set<int> uset;
        for (int i = 1; i <= n/2; i++) {
            if (n % i == 0) {
                uset.insert(i);
            }
        }
        return uset.size() + 1 == 3;
    }
};
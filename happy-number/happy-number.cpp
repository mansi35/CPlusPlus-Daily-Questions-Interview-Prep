class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> visited;
        while (n != 1) {
            if (visited[n])
                return false;
            visited[n] = true;
            int num = n, sum = 0;
            while (num != 0) {
                sum += (num % 10) * (num % 10);
                num /= 10;
            }
            n = sum;
        }
        return true;
    }
};
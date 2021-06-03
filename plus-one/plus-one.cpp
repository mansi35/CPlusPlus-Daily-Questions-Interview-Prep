class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n-1;
        if (digits[n-1] == 9) {
            int flag = false;
            for (int i = 0; i < n; i++) {
               if (digits[i] != 9) {
                   flag = true;
                   break;
               }
            }
            if (flag) {
                while (digits[i] == 9) {
                    digits[i] = 0;
                    i--;
                }
                digits[i] += 1;
                return digits;
            }
            else {
                vector<int> result;
                result.push_back(1);
                for (int i = 1; i <= n; i++) {
                    result.push_back(0);
                }
                return result;
            }
        }
        digits[n-1] += 1;
        return digits;
    }
};
class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int carry = 0;
        int p1 = num1.length() - 1;
        int p2 = num2.length() - 1;
        while (p1 >= 0 || p2 >= 0) {
            int x1 = p1 >= 0 ? num1[p1] - '0' : 0;
            int x2 = p2 >= 0 ? num2[p2] - '0' : 0;
            int value = (x1 + x2 + carry) % 10;
            carry = (x1 + x2 + carry) / 10;
            result += to_string(value);
            p1--;
            p2--;    
        }
        
        if (carry != 0)
            result += to_string(carry);
        reverse(result.begin(), result.end());
        
        return result;
    }
};
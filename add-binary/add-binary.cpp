class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int bit, carry = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 or j >= 0) {
            bit = carry;
            if (i >= 0) {
                bit += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                bit += b[j] - '0';
                j--;
            }
            carry = bit / 2;
            bit = bit % 2;
            result = to_string(bit) + result;
        }
        if (carry)
            result = to_string(carry) + result;
        return result;
    }
};
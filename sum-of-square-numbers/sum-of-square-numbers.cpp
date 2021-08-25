class Solution {
public:
    bool binary_search(long s, long e, int n) {
        if (s > e)
            return false;
        long mid = s + (e - s) / 2;
        if (mid * mid == n)
            return true;
        if (mid * mid > n)
            return binary_search(s, mid - 1, n);
        return binary_search(mid + 1, e, n);
    }
    
    bool judgeSquareSum(int c) {
        for (long i = 0; i * i <= c; i++) {
            int b = c - i * i;
            if (binary_search(0, b, b))
                return true;
        }
        return false;
    }
};
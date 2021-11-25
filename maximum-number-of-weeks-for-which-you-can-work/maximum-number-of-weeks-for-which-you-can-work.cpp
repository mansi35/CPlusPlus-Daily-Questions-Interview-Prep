class Solution {
public:
    long long numberOfWeeks(vector<int>& m) {
        long long maxi = 0, sum = 0;
        for(auto &x: m) sum += x, maxi < x ? maxi = x : maxi ;

        return sum >= maxi*2 ? sum  : (sum - maxi)*2 + 1;
    }
};
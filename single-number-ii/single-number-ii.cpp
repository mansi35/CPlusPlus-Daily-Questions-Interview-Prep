class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt[32] = { 0 };
        for(int n: nums){
            for(int j = 0; j <= 31; j++) {
                int bit= (n & 1);
                cnt[j] += bit;
                n = n >> 1;
                if (!n)
                    break;
            }

        }
        
        int ans = 0;
        for(int i = 0; i <= 31; i++) {
            cnt[i] %= 3;
            ans += (cnt[i] * ((long int)pow(2, i)));
        }
        return ans;
    }
};
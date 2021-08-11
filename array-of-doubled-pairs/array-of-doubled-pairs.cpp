class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int i, int j) {return abs(i) < abs(j);});
        unordered_map<int, int> cnt;
        for (int x: arr)
            cnt[x]++;
        for (int i = 0; i < arr.size(); i++){
            if(cnt[arr[i]] > 0 && cnt[2 * arr[i]] > 0) {
                cnt[arr[i]]--;
                cnt[2 * arr[i]]--;
            }
            else if (cnt[arr[i]] > 0 && cnt[2 * arr[i]] <= 0) {
                return false;
            }
        }
        return true;
    }
};
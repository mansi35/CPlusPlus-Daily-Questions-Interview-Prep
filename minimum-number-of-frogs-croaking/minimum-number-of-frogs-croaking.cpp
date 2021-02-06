class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> croak;
        vector<int> c, k;
        for (int i = 0; i < croakOfFrogs.length(); i++) {
            if (croakOfFrogs[i] == 'c') {
                croak['c'] += 1;
                c.push_back(i);
            }
            if (croakOfFrogs[i] == 'r') {
                if (croak['c'] > croak['r']){
                    croak['r'] += 1;
                }
                else {
                    return -1;
                }
            }
            if (croakOfFrogs[i] == 'o') {
                if (croak['r'] > croak['o']) {
                    croak['o'] += 1;
                }
                else {
                    return -1;
                }  
            } 
            if (croakOfFrogs[i] == 'a') {
                if (croak['o'] > croak['a']) {
                    croak['a'] += 1;
                }
                else {
                    return -1;
                }
            }
            if (croakOfFrogs[i] == 'k') {
                if (croak['a'] > croak['k']) {
                    croak['k'] += 1;
                    k.push_back(i);
                }
                else {
                    return -1;
                }
            }
        }
        if (croak['c'] != croak['r'] || croak['r'] != croak['o'] || croak['o'] != croak['a'] || croak['a'] != croak['k']) {
            return -1;
        }
        int i = 0, j = 0, ans = 0, curr_ans = 0;
        while(i < c.size() && j < c.size()){
            if (c[i] < k[j]){
                curr_ans++;
                i++;
            }
            else if (c[i] > k[j]){
                curr_ans--;
                j++;
            }
            ans = max(ans, curr_ans);
        }
        return ans;
    }
};

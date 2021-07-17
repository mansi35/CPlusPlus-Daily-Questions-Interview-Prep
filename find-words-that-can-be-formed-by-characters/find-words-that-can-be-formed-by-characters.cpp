class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charFreq;
        for (auto ch: chars) {
            charFreq[ch] += 1;
        }
        bool flag;
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            unordered_map<char, int> curWordFreq;
            for (auto ch: words[i]) {
                curWordFreq[ch] += 1;
            }
            flag = true;
            for (auto it : curWordFreq) {
                if(curWordFreq[it.first] > charFreq[it.first]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans += words[i].length();
        }
        return ans;
    }
};
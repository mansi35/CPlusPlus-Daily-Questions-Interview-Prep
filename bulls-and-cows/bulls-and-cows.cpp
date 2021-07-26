class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> umap;
        int i,x = 0,y = 0;
        for (i = 0; i < secret.length(); i++) {
            umap[secret[i]]++;
            if (secret[i] == guess[i]) {
                x++;
                umap[secret[i]]--;
                guess[i] = 'X';
            }
        }
        for (i = 0; i < secret.length(); i++) {
            if (umap[guess[i]] > 0) {
                y++;
                umap[guess[i]]--;
            }
        }
        string s;
        s = s + to_string(x) + "A" + to_string(y) + "B";
        return s;
    }
};
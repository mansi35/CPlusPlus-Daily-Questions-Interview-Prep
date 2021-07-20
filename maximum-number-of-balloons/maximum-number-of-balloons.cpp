class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> umap;
        for (int i = 0; i < text.length(); i++) {
            umap[text[i]] += 1;
        }
        string balloon = "balon";
        int result = INT_MAX;
        for (int i = 0; i < balloon.length(); i++) {
            if (balloon[i] == 'l' or balloon[i] == 'o') {
                result = min(result, umap[balloon[i]] / 2);
            } else {
                result = min(result, umap[balloon[i]]);
            }
        }
        return result;
    }
};
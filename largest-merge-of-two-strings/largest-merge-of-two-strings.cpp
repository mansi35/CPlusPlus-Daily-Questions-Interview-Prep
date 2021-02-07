class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge = "";
        while (!word1.empty() and !word2.empty()) {
            if (word1[0] == word2[0]) {
                if (word1.compare(word2) < 0) {
                    merge += word2[0];
                    word2.erase(0, 1);
                }
                else {
                    merge += word1[0];
                    word1.erase(0, 1); 
                }
            }
            else if (word1[0] > word2[0]) {
                merge += word1[0];
                word1.erase(0, 1);
            }
            else {
                merge += word2[0];
                word2.erase(0, 1);
            }
        }
        if (!word1.empty())
            merge += word1;
        if (!word2.empty())
            merge += word2;
        return merge;
    }
};
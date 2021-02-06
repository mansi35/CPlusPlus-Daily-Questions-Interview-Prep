class Solution {
public:
    string reformat(string s) {
        string letters = "", digits = "";
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i]))
                letters += s[i];
            else
                digits += s[i];
        }
        if (letters.length() == digits.length() + 1 or letters.length() == digits.length() - 1 or letters.length() == digits.length()) {
            string result = "";
            int j = 0, k = 0;
            if (letters.length() > digits.length()) {
                result += letters[j++];
            }
            else 
                result += digits[k++];
            for (int i = 1; i < s.length(); i++) {
                if (isalpha(result[i - 1]))
                    result += digits[k++];
                else
                    result += letters[j++];
            }
            return result;
        }
        
        return "";
    }
};

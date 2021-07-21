class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0, power = columnTitle.size() - 1;
        for(auto i: columnTitle){
            result += pow(26, power)*(i - 'A' + 1);
            power -= 1;
        }
        return result;
    }
};
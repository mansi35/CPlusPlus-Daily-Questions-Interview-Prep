class Solution {
public:
    string interpret(string command) {
        string result = "";
        for (int i = 0; i < command.length();) {
            if (command[i] == '(') {
                if (command[i+1] == ')') {
                    result += 'o';
                    i += 2;
                }
                else {
                    result += "al";
                    i += 4;
                }
            }
            else {
                result += 'G';
                i++;
            }
        }
        return result;
    }
};
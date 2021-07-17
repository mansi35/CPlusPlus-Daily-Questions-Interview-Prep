class Solution {
public:
    vector<string> split(string& s, char delimiter) {
       vector<string> tokens;
       string token;
       istringstream tokenStream(s);
       while (getline(tokenStream, token, delimiter)) {
          tokens.push_back(token);
       }
       return tokens;
    }
    
    bool isValidIPv4(string IPv4) {
        vector<string> xis = split(IPv4, '.');
        if (xis.size() != 4)
            return false;
        for (int i = 0; i < xis.size(); i++) {
            if (xis[i].length() == 0 or xis[i].length() > 3)
                return false;
            if (xis[i][0] == '0' and xis[i].length() > 1)
                return false;
            if (!all_of(xis[i].begin(), xis[i].end(), ::isdigit))
                return false;
            if (stoi(xis[i]) < 0 or stoi(xis[i]) > 255)
                return false;
        }
        return true;
    }
    
    bool isValidIPv6(string IPv6) {
        vector<string> xis = split(IPv6, ':');
        if (xis.size() != 8)
            return false;
        string hexdigits = "0123456789abcdefABCDEF";
        for (int i = 0; i < xis.size(); i++) {
            if (xis[i].length() == 0 or xis[i].length() > 4)
                return false;
            for (char ch: xis[i]) {
                if (hexdigits.find(ch) == string::npos)
                    return false;
            }
        }
        return true;
    }
    
    string validIPAddress(string IP) {
        if (count(IP.begin(), IP.end(), '.') == 3) {
            if (isValidIPv4(IP))
                return "IPv4";
            return "Neither";
        } else if (count(IP.begin(), IP.end(), ':') == 7) {
            if (isValidIPv6(IP))
                return "IPv6";
            return "Neither";
        } else {
            return "Neither";
        }
    }
};
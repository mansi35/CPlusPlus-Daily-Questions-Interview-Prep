class Solution {
public:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
     vector<string> teens = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    string generateThreeNames(int n) {
        string result = "";
        if(n / 100 > 0)
            result += ones[n / 100] + " Hundred";
        
        if(n / 100 > 0 && n % 100 > 0) result += " ";
        
        int t = n % 100;
        if(t >= 20 or t <= 10) {
            if(t / 10 > 0)
                result += tens[t / 10];
            
            if(t / 10 > 0 && t % 10 > 0) result += " ";
            
            if(t % 10 > 0)
                result += ones[t % 10];
        } else {
            result += teens[t % 10];
        }
        return result;
    }
    
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        
        string res = "";
        res = generateThreeNames(num % 1000) + res;
        num /= 1000;
        
        if(num > 0) {
            if(num % 1000 > 0)
                res = generateThreeNames(num % 1000) + " Thousand " + res;
            num /= 1000;
        }
        
        if(num > 0) {
            if(num % 1000 > 0)
                res = generateThreeNames(num % 1000) + " Million " + res;
            num /= 1000;
        }
        
        if(num > 0) {
            res = generateThreeNames(num % 1000) + " Billion " + res;
        }
        
        if(res.back() == ' ') res.pop_back();
        
        return res;
    }
};
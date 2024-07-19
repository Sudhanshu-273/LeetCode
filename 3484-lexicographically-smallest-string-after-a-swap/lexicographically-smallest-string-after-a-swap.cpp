class Solution {
public:
    string getSmallestString(string s) {
        for(int i = 0; i < s.length() - 1; ++i) {
            int num1 = s[i] - '0';
            int num2 = s[i + 1] - '0';
            if((num1 & 1) && (num2 & 1) && num1 > num2) {
                swap(s[i], s[i + 1]);
                return s;
            } 
            if((!(num1 & 1)) && (!(num2 & 1)) && num1 > num2) {
                swap(s[i], s[i + 1]);
                return s;
            }
        }
        return s;
    }
};
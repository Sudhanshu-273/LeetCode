class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(auto ch: s) {
            mp[ch]++;
        }
        int maxi = 0;
        int sum = 0;
        for(auto it : mp) {
            // cout << it.first << " -> " << it.second << "\n";
            if(it.second & 1) {
                maxi = 1;
                sum += it.second - 1;
            } else {
                sum += it.second;
            }
        }

        return sum + maxi;
    }
};
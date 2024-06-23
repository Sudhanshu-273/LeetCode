class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        map<char, int> mp;
        int n = s.length();
        int maxlen = 0;
        while(r < n) {
            mp[s[r]]++;
            while(mp[s[r]] > 1) {
                mp[s[l]]--;
                ++l;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
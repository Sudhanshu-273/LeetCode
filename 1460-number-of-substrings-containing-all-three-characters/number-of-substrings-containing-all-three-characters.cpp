class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0;
        map<char, int> mp;
        int n = s.length();
        int count = 0;
        while(r < n) {
            mp[s[r]]++;
            while(mp.size() >= 3) {
                count += (n - r);
                mp[s[l]]--;
                if(mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                ++l;
            }
            r++;
        }
        return count;
    }
};
class Solution {
public:
    bool check(map<char, int>& mp, int k) {
        int maxi = 0;
        int sum = 0;
        for (auto it : mp) {
            sum += it.second;
            maxi = max(maxi, it.second);
        }

        return (sum - maxi) <= k;
    }

    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int n = s.length();
        map<char, int> mp;
        while (r < n) {
            mp[s[r]]++;
            while (!check(mp, k)) {
                mp[s[l]]--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};
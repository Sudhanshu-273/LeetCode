class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> v;
        for(int i = 0; i < s.length(); ++i) {
            v.push_back(abs(s[i] - t[i]));
        }
        int n = s.length();
        int l = 0, r = 0;
        int ans = 0;
        int sum = 0;
        while(r < n) {
            sum += v[r];
            while(sum > maxCost) {
                sum -= v[l];
                l++;
            }
            ans = max(ans, r - l + 1);
            ++r;
        }
        return ans;
    }
};
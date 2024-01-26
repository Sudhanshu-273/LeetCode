class Solution {
public:

    int lcs(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        if(i < 0 || j < 0)  return 0;

        if(dp[i][j] != -1)  return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = 1 + lcs(s, t, i - 1, j - 1, dp);

        else return dp[i][j] = max(lcs(s, t, i - 1, j, dp), lcs(s, t, i, j - 1, dp));
    }

    int minDistance(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        int val = lcs(s, t, n - 1, m - 1, dp);
        return n + m - (2 * val);
    }
};
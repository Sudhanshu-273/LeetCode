class Solution {
public:

    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        // base

        if(j < 0)
            return i + 1;
        if(i < 0)
            return j + 1;

        if(dp[i][j] != -1) {
            return dp[i][j];
        }


        //
        int a = 1e6, b = 1e6, c = 1e6, d = 1e6;
        if(s[i] == t[j]) {
            a = solve(s, t, i - 1, j - 1, dp);
        } else {
            // insert
            b = 1 + solve(s, t, i, j - 1, dp);
            // delete
            c = 1 + solve(s, t, i - 1, j, dp);

            // replace
            d = 1 + solve(s, t, i - 1, j - 1, dp);
        }

        return dp[i][j] =min(a, min(b, min(c, d)));
    }

    int minDistance(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        if(m == 0) {
            return n; 
        }
        return solve(s, t, n - 1, m - 1, dp);
    }
};
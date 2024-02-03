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
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

        for(int i = 0; i <= n; ++i) {
            dp[i][0] = i + 1;
        }
        for(int i = 0; i <= m; ++i) {
            dp[0][i] = i + 1;
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + dp[i][j - 1];
                    dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
                    dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - 1]);
                }
            }
        }

        return dp[n][m] - 1;
        // return solve(s, t, n - 1, m - 1, dp);
    }
};
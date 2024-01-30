class Solution {
public:
    int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (j < 0) {
            return 1;
        }
        if (i < 0 && j < 0) {
            return 1;
        }
        if(i < 0 && j >= 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int x = 0, y = 0, z = 0;
        if (s[i] == t[j]) {
            x = solve(s, t, i - 1, j - 1, dp);
            y = solve(s, t, i - 1, j, dp);
        } else {
            z = solve(s, t, i - 1, j, dp);
        }

        return dp[i][j] = x + y + z;
    }

    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(s, t, n - 1, m - 1, dp);
    }
};
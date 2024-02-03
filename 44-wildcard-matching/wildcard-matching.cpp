class Solution {
public:

    bool solve(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        if(i < 0 && j >= 0)
            return false;
        if(i < 0 && j < 0)
            return true;

        if(j < 0 && i >= 0) {
            while(i >= 0) {
                if(s[i] != '*')
                    return false;
                --i;
            }
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }


        if(s[i] == t[j]) {
            return dp[i][j] = solve(s, t, i - 1, j - 1, dp);
        } else {
            if(s[i] == '?') {
                return dp[i][j] = solve(s, t, i - 1, j - 1, dp);
            } else if(s[i] == '*') {
                return dp[i][j] = (solve(s, t, i, j - 1, dp) || solve(s, t, i - 1, j - 1, dp) || solve(s, t, i - 1, j, dp));
            } else {
                return dp[i][j] = false;
            }
        }
    }

    bool isMatch(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        return solve(t, s, m - 1, n - 1, dp);
    }
};
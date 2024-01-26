class Solution {
public:

    int lps(string &s, int i, int j, vector<vector<int>> &dp) {
        if(i == j)return 1;
        if(i > j) return 0;

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s[i] == s[j]) return dp[i][j] = 2 + lps(s, i + 1, j - 1, dp);
        else return dp[i][j] = max(lps(s, i + 1, j, dp), lps(s, i, j - 1, dp)); 
    }

    int minInsertions(string s) {
        int n = s.length();
        int i = 0, j = s.length() - 1;
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return s.length() - lps(s, i, j, dp);
    }
};
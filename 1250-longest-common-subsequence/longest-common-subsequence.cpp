class Solution {
public:

    int f(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if(i < 0 || j < 0) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s1[i] == s2[j]) {
            return dp[i][j] = 1 + f(s1, s2, i - 1, j - 1, dp);
        } else {
            return dp[i][j] = max(f(s1, s2, i - 1, j, dp), f(s1, s2, i, j - 1, dp));
        }

    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.length();
        int j = text2.length();
        vector<vector<int>> dp(i + 1, vector<int> (j + 1, 0));

        for(int x = 1; x <= i; ++x) {
            for(int y = 1; y <= j; ++y) {
                if(text1[x - 1] == text2[y - 1]) {
                    dp[x][y] = 1 + dp[x - 1][y - 1];
                } else {
                    dp[x][y] = max(dp[x - 1][y], dp[x][y - 1]);
                }
            }
        }

        return dp[i][j];

        



        // return f(text1, text2, i - 1, j - 1, dp);
    }
};
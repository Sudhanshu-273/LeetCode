class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string str = "";

        int i = n, j = m;
        while(i > 0 && j > 0) {
            if(dp[i][j] == dp[i - 1][j]) {
                str.push_back(s[i - 1]);
                --i;
            } else if(dp[i][j] == dp[i][j - 1]) {
                str.push_back(t[j - 1]);
                --j;
            } else {
                str.push_back(t[j - 1]);
                --i;
                --j;
            }
        }

        while(i > 0) {
            str.push_back(s[i - 1]);
            --i;
        }

        while(j > 0) {
            str.push_back(t[j - 1]);
            --j;
        }

        reverse(str.begin(), str.end());


        return str;



    }
};
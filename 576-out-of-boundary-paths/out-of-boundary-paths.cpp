class Solution {
public:

    int mod = 1e9+7;

    int solve(int m, int n, int maxMove, int i, int j, vector<vector<vector<int>>> &dp) {
        if(i < 0 || j < 0 || i == m || j == n) {
            return 1;
        }

        if(maxMove == 0)
            return 0;

        if(dp[i][j][maxMove] != -1) {
            return dp[i][j][maxMove];
        }

        int l = 0, r = 0, u = 0, d = 0;

        l = solve(m, n, maxMove - 1, i, j - 1, dp) % mod;
        r = solve(m, n, maxMove - 1, i, j + 1, dp) % mod;
        u = solve(m, n, maxMove - 1, i - 1, j, dp) % mod;
        d = solve(m, n, maxMove - 1, i + 1, j, dp) % mod;

        return dp[i][j][maxMove] = ((((l % mod) + (r % mod)) % mod) + (((u % mod) + (d % mod)) % mod)) % mod;
        
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>> (n + 1, vector<int> (maxMove + 1, -1)));
        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
};
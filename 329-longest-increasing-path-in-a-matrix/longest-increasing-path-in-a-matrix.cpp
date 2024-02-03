class Solution {
public:

    bool check(int i, int n) {
        if(i < 0 || i >= n)
            return false;
        return true;
    }


    int solve(vector<vector<int>>& v, int i, int j, vector<vector<int>> &dp) {
        int n = v.size(), m = v[0].size();
        if(i >= n || j >= m || i < 0 || j < 0)
            return 0;
            
            
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int l = 0, r = 0, u = 0, d = 0;
        if(check(i - 1, n) && v[i - 1][j] > v[i][j]) {
            u = 1 + solve(v, i - 1, j, dp);
        }
        
        if(check(i + 1, n) && v[i + 1][j] > v[i][j]) {
            d = 1 + solve(v, i + 1, j, dp);
        }
        
        if(check(j - 1, m) && v[i][j - 1] > v[i][j]) {
            l = 1 + solve(v, i, j - 1, dp);
        }
        
        if(check(j + 1, m) && v[i][j + 1] > v[i][j]) {
            r = 1 + solve(v, i, j + 1, dp);
        }
        
        return dp[i][j] = max(l, max(r, max(u, d)));
        
        
    }

    int longestIncreasingPath(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        int maxi = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(dp[i][j] == -1) {
                    maxi = max(maxi, 1 + solve(v, i, j, dp));
                }
            }
        }
        
        return maxi;
    }
};
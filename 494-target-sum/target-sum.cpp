class Solution {
public:

    int solve(vector<int>& v, int idx, int sum, int x, vector<vector<int>> &dp) {
        if(idx == v.size()) {
            if(x == (sum - 1000))
                return 1;
            else return 0;
        }

        if(dp[idx][sum] != -1) {
            return dp[idx][sum];
        }

        int plus = 0, minus = 0;

        plus = solve(v, idx + 1, sum + v[idx], x, dp);

        minus = solve(v, idx + 1, sum - v[idx], x, dp);

        return dp[idx][sum] = plus + minus;

    }

    int findTargetSumWays(vector<int>& v, int x) {
        vector<vector<int>> dp(v.size() + 1, vector<int> (2001, -1));
        return solve(v, 0, 1000, x, dp);
    }
};
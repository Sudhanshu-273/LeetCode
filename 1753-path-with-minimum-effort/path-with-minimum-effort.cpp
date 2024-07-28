class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        // vector<vector<bool>> vis(n, vector<bool> (m, false));
        dist[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        // vis[0][0] = true;
        while(!pq.empty()) {
            int d = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if(i + 1 < n) {
                int diff = abs(grid[i][j] - grid[i + 1][j]);
                int val = max(diff, d);
                if(val < dist[i + 1][j]) {
                    dist[i + 1][j] = val;
                    pq.push({val, {i + 1, j}});
                }
            }
            if(j + 1 < m) {
                int diff = abs(grid[i][j] - grid[i][j + 1]);
                int val = max(diff, d);
                if(val < dist[i][j + 1]) {
                    dist[i][j + 1] = val;
                    pq.push({val, {i, j + 1}});
                }
            }
            if(i > 0) {
                int diff = abs(grid[i][j] - grid[i - 1][j]);
                int val = max(diff, d);
                if(val < dist[i - 1][j]) {
                    dist[i - 1][j] = val;
                    pq.push({val, {i - 1, j}});
                }
            }
            if(j > 0) {
                int diff = abs(grid[i][j] - grid[i][j - 1]);
                int val = max(diff, d);
                if(val < dist[i][j - 1]) {
                    dist[i][j - 1] = val;
                    pq.push({val, {i, j - 1}});
                }
            }
        }

        return dist[n - 1][m - 1];

    }
};
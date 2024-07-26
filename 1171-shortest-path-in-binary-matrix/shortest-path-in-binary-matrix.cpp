class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        dist[0][0] = 0;
        if(grid[0][0] != 0) {
            return -1;
        }

        queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, 0}});
        vis[0][0] = true;
        while(!pq.empty()) {
            int d = pq.front().first;
            int i = pq.front().second.first;
            int j = pq.front().second.second;
            pq.pop();

            if(i < n - 1 && grid[i + 1][j] == 0 && !vis[i + 1][j]) {
                    vis[i + 1][j] = true;
                    dist[i + 1][j] = d + 1;
                    pq.push({d + 1, {i + 1, j}});
            }
            if(i > 0 && grid[i - 1][j] == 0 && !vis[i - 1][j]) {
                    vis[i - 1][j] = true;
                    dist[i - 1][j] = d + 1;
                    pq.push({d + 1, {i - 1, j}});
            }
            if(j < n - 1 && grid[i][j + 1] == 0 && !vis[i][j + 1]) {
                    vis[i][j + 1] = true;
                    dist[i][j + 1] = d + 1;
                    pq.push({d + 1, {i, j + 1}});
            }
            if(j > 0 && grid[i][j - 1] == 0 && !vis[i][j - 1]) {
                    vis[i][j - 1] = true;
                    dist[i][j - 1] = d + 1;
                    pq.push({d + 1, {i, j - 1}});
            }


            if(i < n - 1 && j < n - 1 && grid[i + 1][j + 1] == 0 && !vis[i + 1][j + 1]) {
                    vis[i + 1][j + 1] = true;
                    dist[i + 1][j + 1] = d + 1;
                    pq.push({d + 1, {i + 1, j + 1}});
            }
            if(i > 0 && j > 0 && grid[i - 1][j - 1] == 0 && !vis[i - 1][j - 1]) {
                    vis[i - 1][j - 1] = true;
                    dist[i - 1][j - 1] = d + 1;
                    pq.push({d + 1, {i - 1, j - 1}});
            }
            if(i > 0 && j < n - 1 && grid[i - 1][j + 1] == 0 && !vis[i - 1][j + 1]) {
                    vis[i - 1][j + 1] = true;
                    dist[i - 1][j + 1] = d + 1;
                    pq.push({d + 1, {i - 1, j + 1}});
            }
            if(i < n - 1 && j > 0 && grid[i + 1][j - 1] == 0 && !vis[i + 1][j - 1]) {
                    vis[i + 1][j - 1] = true;
                    dist[i + 1][j - 1] = d + 1;
                    pq.push({d + 1, {i + 1, j - 1}});
            }
            
        }

        if(dist[n - 1][n - 1] == INT_MAX) return -1;
        else return dist[n - 1][n - 1] + 1;

    }
};
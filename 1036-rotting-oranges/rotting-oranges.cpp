class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> qe;
        int n = grid.size(), m = grid[0].size();
        bool found = false;
        int count = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 2) {
                    qe.push({{i, j}, 0});
                }
                if(grid[i][j] == 1) ++count;
            }
        }
        int ans = 0;
        while(!qe.empty()) {
            int x = qe.front().first.first;
            int y = qe.front().first.second;
            int level = qe.front().second;
            ans = max(ans, level);
            qe.pop();

            if(x > 0) {
                if(grid[x - 1][y] == 1) {
                    --count;
                    grid[x - 1][y] = 2;
                    qe.push({{x - 1, y}, level + 1});
                }
            }
            if(x < n - 1) {
                if(grid[x + 1][y] == 1) {
                    --count;
                    grid[x + 1][y] = 2;
                    qe.push({{x + 1, y}, level + 1});
                }
            }
            if(y > 0) {
                if(grid[x][y - 1] == 1) {
                    --count;
                    grid[x][y - 1] = 2;
                    qe.push({{x, y - 1}, level + 1});
                }
            }
            if(y < m - 1) {
                if(grid[x][y + 1] == 1) {
                    --count;
                    grid[x][y + 1] = 2;
                    qe.push({{x, y + 1}, level + 1});
                }
            }
        }
        if(count == 0) {
            return ans;
        } else return -1;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> v(n, vector<int> (m, -1));
        queue<pair<pair<int, int>, int>> qe;
        for(int i = 0; i < n ; ++i) {
            for(int j = 0; j < m; ++j) {
                if(mat[i][j] == 0) {
                    v[i][j] = 0;
                    qe.push({{i, j}, 0});
                }
            }
        }

        while(!qe.empty()) {
            int x = qe.front().first.first;
            int y = qe.front().first.second;
            int d = qe.front().second;
            qe.pop();
            // cout << " -> " << x << " " << y << endl;

            if(x > 0 && mat[x - 1][y] == 1 && v[x - 1][y] == -1) {
                v[x - 1][y] = d + 1;
                qe.push({{x - 1, y}, d + 1});
                // cout << x - 1 << y << endl;
            }
            if(y > 0 && mat[x][y - 1] == 1 && v[x][y - 1] == -1) {
                v[x][y - 1] = d + 1;
                qe.push({{x, y - 1}, d + 1});
                // cout << x << y - 1 << endl;
            }
            if(x < n - 1 && mat[x + 1][y] == 1 && v[x + 1][y] == -1) {
                v[x + 1][y] = d + 1;
                qe.push({{x + 1, y}, d + 1});
                // cout << x + 1 << y << endl;
            }
            if(y < m - 1 && mat[x][y + 1] == 1 && v[x][y + 1] == -1) {
                v[x][y + 1] = d + 1;
                qe.push({{x, y + 1}, d + 1});
                // cout << x << y + 1 << endl;
            }
        }
        return v;
    }
};
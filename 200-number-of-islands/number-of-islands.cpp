class Solution {
public:

    void dfs(vector<vector<char>>& v, int i, int j, vector<vector<bool>> &vis) {
        int n = v.size(), m = v[0].size();

        // left
        if(j > 0 && v[i][j - 1] == '1' && !vis[i][j - 1]) {
            vis[i][j - 1] = true;
            dfs(v, i, j - 1, vis);
        }


        // right
        if(j < m - 1 && v[i][j + 1] == '1' && !vis[i][j + 1]) {
            vis[i][j + 1] = true;
            dfs(v, i, j + 1, vis);
        }

        // top
        if(i > 0 && v[i - 1][j] == '1' && !vis[i - 1][j]) {
            vis[i - 1][j] = true;
            dfs(v, i - 1, j, vis);
        }

        // bottom
        if(i < n - 1 && v[i + 1][j] == '1' && !vis[i + 1][j]) {
            vis[i + 1][j] = true;
            dfs(v, i + 1, j, vis);
        }

    }

    int numIslands(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));

        int count = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(!vis[i][j] && v[i][j] == '1')
                {
                    ++count;
                    vis[i][j] = true;
                    dfs(v, i, j, vis);
                }
            }
        }
        return count;
    }
};
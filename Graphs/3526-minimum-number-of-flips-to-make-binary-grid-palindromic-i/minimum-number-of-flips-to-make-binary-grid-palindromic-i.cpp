class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        // checking for rows

        int count = 0;
        for(int i = 0; i < grid.size(); ++i) {
            int s = 0, e = grid[0].size() - 1;
            while(s < e) {
                if(grid[i][s] != grid[i][e])
                    ++count;
                ++s;
                --e;
            }
        }
        int mini = count;
        // return count;
        count = 0;
        for(int j = 0; j < grid[0].size(); ++j) {
            int s = 0, e = grid.size() - 1;
            while(s < e) {
                if(grid[s][j] != grid[e][j])
                    ++count;
                ++s;
                --e;
            }
        }
        mini = min(mini, count);
        return mini;
    }
};
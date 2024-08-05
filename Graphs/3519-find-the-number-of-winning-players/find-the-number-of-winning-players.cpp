class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<map<int, int>> v(n);
        // map<int, map<int, int>> mp;
        for(int i = 0; i < pick.size(); ++i) {
            int x = pick[i][0];
            int y = pick[i][1];
            v[x][y]++;
        }
        int count = 0;
        for(int i = 0; i < n; ++i) {
            for(auto e : v[i]) {
                if(e.second > i) {
                    ++count;
                    break;
                }
            }
        }
        return count;
    }
};
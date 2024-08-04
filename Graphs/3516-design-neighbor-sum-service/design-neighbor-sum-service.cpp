class neighborSum {
    map<int, pair<int, int>> mp;
    int n;
    int m;
    vector<vector<int>> grid;
public:


    neighborSum(vector<vector<int>>& grid) {
        this -> n = grid.size();
        this -> m = grid[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                mp[grid[i][j]] = {i, j};
            }
        }
        this -> grid = grid;
    }
    
    int adjacentSum(int value) {
        int i = mp[value].first;
        int j = mp[value].second;
        int sum = 0;
        if(i > 0) {
            sum += grid[i - 1][j];
        }
        if(j > 0) {
            sum += grid[i][j - 1];
        } 
        if(i < n - 1) {
            sum += grid[i + 1][j];
        }
        if(j < m - 1) {
            sum += grid[i][j + 1];
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        int i = mp[value].first;
        int j = mp[value].second;
        int sum = 0;
        if(i > 0 && j > 0) {
            sum += grid[i - 1][j - 1];
        }
        if(i < n - 1 && j > 0) {
            sum += grid[i + 1][j - 1];
        } 
        if(i > 0 && j < m - 1) {
            sum += grid[i - 1][j + 1];
        }
        if(j < m - 1 && i < n - 1) {
            sum += grid[i + 1][j + 1];
        }
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n = v.size();
        for(int i = 0; i < n - i - 1; ++i) {
            for(int j = i; j < n - i - 1; ++j) {
                cout << "i = " << i << " j = " << j << endl;
                int x = i, y = j;
                int c = n - 1 - x, r = y;
                int val = v[x][y];
                cout << r << " rc " << c << " val = " << val << endl;
                swap(v[r][c], val);
                x = r; y = c;
                r = y; c = n - 1 - x;
                cout << r << " rc " << c << " val = " << val << endl;
                swap(v[r][c], val);
                x = r; y = c;
                r = y; c = n - 1 - x;
                cout << r << " rc " << c << " val = " << val << endl;
                swap(v[r][c], val);
                v[i][j] = val;
                cout << i << " rc " << j << " val = " << val << endl;
            }
        }
    }
};
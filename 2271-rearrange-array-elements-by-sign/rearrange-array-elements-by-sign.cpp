class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        
        int n = v.size();

        
        vector<int> neg, pos;
        
        for (int i = 0; i < n; ++i) {
            if (v[i] > 0) {
                pos.push_back(v[i]);
            } else {
                neg.push_back(v[i]);
            }
        }

        bool flag = true;

        for (int i = 0; i < n / 2; ++i) {
            v[2 * i] = pos[i];
        }

        for (int i = 0; i < n / 2; ++i) {
            v[(2 * i) + 1] = neg[i];
        }

        return v;

    }
};
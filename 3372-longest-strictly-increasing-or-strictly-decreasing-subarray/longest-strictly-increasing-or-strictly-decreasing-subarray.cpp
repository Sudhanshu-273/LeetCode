class Solution {
public:
    int longestMonotonicSubarray(vector<int>& v) {
        int count = 1;
        int maxi = 0;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i - 1] < v[i]) {
                ++count;
            } else {
                maxi = max(maxi, count);
                count = 1;
            }
        }
        // if(count != 0)
            maxi = max(maxi, count);
        count = 1;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i - 1] > v[i]) {
                ++count;
            } else {
                maxi = max(maxi, count);
                count = 1;
            }
        }
        // if(count != 0)
            maxi = max(maxi, count);
        return maxi;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int l = 0, r = 0;
        int sum = 0;
        int maxi = INT_MIN;
        while(r < v.size()) {
            sum += v[r];
            maxi = max(sum, maxi);
            if(sum < 0) {
                sum = 0;
                r++;
                l = r;
            } else r++;
        }
        return maxi;
    }
};
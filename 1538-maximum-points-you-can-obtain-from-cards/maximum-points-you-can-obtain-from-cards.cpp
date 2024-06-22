class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        int num = n - k;
        int l = 0, r = 0;
        int sum = 0, min_sum = INT_MAX;
        int total = 0;
        for(int i = 0; i < n; ++i) {
            total += v[i];
        }
        if(num == 0) {
            return total;
        }
        while(r <= num - 1) {
            sum += v[r];
            ++r;
        }
        min_sum = min(min_sum, sum);
        // ++r;
        while(r < n) {
            sum -= v[l];
            ++l;
            sum += v[r];
            ++r;
            min_sum = min(min_sum, sum);
        }
        return total - min_sum;
    }
};
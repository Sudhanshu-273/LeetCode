class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        vector<int> v(n, 0);
        for(int i = 0; i < n; ++i) {
            if(grumpy[i] == 1) {
                v[i] = customers[i];
            }
        }
        int sum = 0;
        int l = 1, r = 0;
        int maxi = 0;
        while(r < minutes) {
            sum += v[r];
            ++r;
        }
        int idx = 0;
        maxi = max(maxi, sum);
        while(r < n) {
            sum -= v[l - 1];
            sum += v[r];
            if(sum > maxi) {
                idx = l;
            }
            maxi = max(sum, maxi);
            ++r;
            ++l;
        }
        int range = idx + minutes - 1;
        cout << idx << " " << range;

        int total = 0;
        for(int i = 0; i < n; ++i) {
            if(i >= idx && i <= range) {
                total += customers[i];
            } else if(grumpy[i] == 0) {
                total += customers[i];
            }
        }
        return total;

    }
};
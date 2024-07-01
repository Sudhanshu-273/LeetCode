class Solution {
public:

    int countDays(vector<int> &v, int mid) {
        int sum = 0;
        int count = 0;
        for(int i = 0; i < v.size(); ++i) {
            if(v[i] > mid) return INT_MAX;
            sum += v[i];
            if(sum > mid) {
                ++count;
                sum = v[i];
            }
        }
        return count + 1;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1, high = 1e9;
        int ans = 0;
        while(low <= high) {
            int mid = ((high - low) / 2) + low;
            int k = countDays(weights, mid);
            // cout << mid << " " << k << endl;
            if(k > days) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};
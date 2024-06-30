class Solution {
public:

    int countDays(vector<int> &v, int k, int mid) {
        int count = 0, adj = 0;
        for(int i = 0; i < v.size(); ++i) {
            if(v[i] <= mid) {
                ++adj;
                if(adj == k) {
                    ++count;
                    adj = 0;
                }
            } else {
                adj = 0;
            }
        }
        return count;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, high = 1e9;
        int ans = -1;
        while(low <= high) {
            int mid = ((high - low) / 2) + low;
            int count = countDays(bloomDay, k, mid);
            if(count >= m) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};
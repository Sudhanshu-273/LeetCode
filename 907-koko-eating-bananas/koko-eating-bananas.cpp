class Solution {
public:

    int findk(vector<int> &v, int h, int mid) {
        int count = 0;
        int sum = 0;
        for(int i = 0; i < v.size(); ++i) {
            if(v[i] < mid) {
                ++count;
            } else {
                int val = v[i] / mid;
                count += val;
                if(v[i] % mid != 0)
                    ++count;
            }
        }

        return count;

    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // sort(piles.begin(), piles.end());
        int low = 1, high = INT_MAX;
        int ans = INT_MAX;
        while(low <= high) {
            int mid = ((high - low) / 2) + low;
            // int mid = 23;
            int k = findk(piles, h, mid);
            // cout << "->" <<mid << " " << k << endl;
            if(k <= h) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            // break;
        }
        return ans;
    }
};
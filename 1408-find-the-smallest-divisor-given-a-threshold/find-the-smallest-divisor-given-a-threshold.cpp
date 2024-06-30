class Solution {
public:

    int divisionResult(vector<int> &v, int mid) {
        int count = 0;
        for(int i = 0; i < v.size(); ++i) {
            count += (v[i] / mid);
            if(v[i] % mid != 0)
                ++count;
        }
        return count;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = 1e6;
        int ans = 1;
        while(low <= high) {
            int mid = ((high - low) / 2) + low;
            int val = divisionResult(nums, mid);
            // cout << mid << " " << val << endl;
            if(val <= threshold) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};
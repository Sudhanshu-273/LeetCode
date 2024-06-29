class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return x;
        int low = 1, high = x;
        int ans = 1;
        while(low <= high) {
            int mid = ((high - low) / 2) + low;
            if(mid <= (x / mid)) {
                ans = mid;
                // cout << ans << " " << low << " " << high;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
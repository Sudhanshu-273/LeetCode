class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return x;
        int low = 1, high = x;
        int ans = 1;
        while(low <= high) {
            long long mid = ((high - low) / 2) + low;
            if(mid * mid == x) {
                return mid;
            } else if(mid * mid < x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
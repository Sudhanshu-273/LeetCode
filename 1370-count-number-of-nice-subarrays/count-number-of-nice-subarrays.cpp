class Solution {
public:

    int subarrays(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        int l = 0, r = 0;
        int n = nums.size();
        int count = 0;
        int ans = 0;
        while(r < n) {
            if((nums[r] & 1)) {
                ++count;
            }
            while(count > k) {
                if((nums[l] & 1)) {
                    --count;
                }
                ++l;
            }
            ans += (r - l + 1);
            ++r;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int val = subarrays(nums, k) - subarrays(nums, k - 1);
        return val >= 0 ? val : 0;
    }
};
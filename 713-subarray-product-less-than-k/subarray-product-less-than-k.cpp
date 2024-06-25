class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0 || k == 1)
            return 0;
        int l = 0, r = 0, n = nums.size();
        int count = 0;
        int sum = 1;
        while(r < n) {
            sum *= nums[r];
            while(sum >= k) {
                sum /= nums[l];
                ++l;
            }
            count += (r - l + 1);
            ++r;
        }
        return count;
    }
};
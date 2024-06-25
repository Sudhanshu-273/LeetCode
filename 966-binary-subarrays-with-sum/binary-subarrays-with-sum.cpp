class Solution {
public:
    int subarrays(vector<int>& nums, int goal) {
        if(goal < 0)
            return 0;
        int l = 0, r = 0;
        int count = 0;
        int sum = 0;
        int n = nums.size();
        while (r < n) {
            sum += nums[r];
            while (sum > goal && l < n) {
                sum -= nums[l];
                ++l;
            }
            count += (r - l + 1);
            ++r;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int val = subarrays(nums, goal) - subarrays(nums, goal - 1);
        return val >= 0 ? val : 0;
    }
};
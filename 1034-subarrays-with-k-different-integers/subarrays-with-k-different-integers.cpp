class Solution {
public:

    int subarrays(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        int l = 0, r = 0, n = nums.size();
        int count = 0;
        map<int, int> mp;
        while(r < n) {
            mp[nums[r]]++;
            while(mp.size() > k) {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) 
                    mp.erase(nums[l]);
                ++l;
            }
            count += (r - l + 1);
            ++r;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int val = subarrays(nums, k) - subarrays(nums, k - 1);
        return val >= 0 ? val : 0;
    }
};
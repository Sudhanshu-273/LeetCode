class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();
        int count = 0;
        int maxlen = 0;
        while(r < n) {
            if(nums[r] == 0) {
                while(count >= k) {
                    if(nums[l] == 0) {
                        ++l;
                        --count;
                    } else {
                        ++l;
                    }
                }
                ++count;
            }

            maxlen = max(maxlen, r - l + 1);
            ++r;
        }

        return maxlen;
    }
};
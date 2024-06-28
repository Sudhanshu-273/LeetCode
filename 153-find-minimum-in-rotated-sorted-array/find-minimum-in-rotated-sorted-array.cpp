class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = ((high - low) / 2) + low;
            if (low == mid) {
                if (nums[low] < nums[high]) {
                    return nums[low];
                } else
                    return nums[high];
            } else {
                if(nums[low] > nums[mid]) {
                    high = mid;
                } else if(nums[mid] > nums[high]) {
                    low = mid;
                } else {
                    return nums[low];
                }
            }
        }
        return 0;
    }
};
class Solution {
public:

    int first(vector<int> nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = -1;
        while(low <= high) {
            int mid = ((high - low) / 2) + low;
            if(nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }

    int last(vector<int> nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = -1;
        while(low <= high) {
            int mid = ((high - low) / 2) + low;
            if(nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums, target), last(nums, target)};      
    }
};
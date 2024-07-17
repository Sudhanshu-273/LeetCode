class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c1 = 0, v1 = INT_MIN, c2 = 0, v2 = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) {
            if(v1 == nums[i]) {
                c1++;
            } else if(v2 == nums[i]) {
                c2++;
            } else if(c1 == 0) {
                c1 = 1;
                v1 = nums[i];
            } else if(c2 == 0) {
                c2 = 1;
                v2 = nums[i];
            } else {
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        c1 = 0;
        c2 = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == v1) c1++;
            if(nums[i] == v2) c2++;
        }
        if(c1 > (n / 3)) ans.push_back(v1);
        if(c2 > (n / 3)) ans.push_back(v2);
        return ans;
    }
};
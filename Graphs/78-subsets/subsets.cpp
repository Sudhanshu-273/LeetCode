class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < (1 << n); ++i) {
            int num = i;
            vector<int> v;
            for(int j = 0; j < n; ++j) {
                if((num >> j) & 1) {
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
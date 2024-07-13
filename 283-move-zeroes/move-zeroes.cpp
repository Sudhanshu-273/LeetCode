class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int x = nums.size(), y = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0){
                x = i;
                break;
            }
        }
        y = x + 1;
        while(y < nums.size()) {
            if(nums[y] != 0) {
                swap(nums[x], nums[y]);
                x++;
                y++;
            } else y++;
        }
    }
};
class Solution {
public:
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> v(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            string num = to_string(nums[i]);
            for (int j = 0; j < num.length(); ++j) {
                num[j] = (int(mapping[num[j] - '0'] + '0'));
            }
            v[i] = {nums[i], stoi(num)};
        }

        sort(v.begin(), v.end(), comp);
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            ans[i] = v[i].first;
        }
        return ans;
    }
};
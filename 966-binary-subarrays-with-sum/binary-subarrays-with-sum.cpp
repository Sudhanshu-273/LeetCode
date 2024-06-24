class Solution {
public:

    int noofsubarrays(vector<int>& v, int k) {
        int presum = 0, count = 0;
        map<int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < v.size(); ++i){
            presum += v[i];
            if(mp.find(presum - k) != mp.end()) {
                count += mp[presum - k];
            }
            mp[presum]++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& v, int goal) {
        int val = noofsubarrays(v, goal);
        return val;
    }
};
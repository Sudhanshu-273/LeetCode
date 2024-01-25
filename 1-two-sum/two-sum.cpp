#define ff first
#define ss second
class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int s = 0, e = v.size() - 1;
        vector<pair<int, int>> vp(v.size());
        for(int i = 0; i < v.size(); ++i) {
            vp[i] = {v[i], i};
        }
        sort(vp.begin(), vp.end());
        while(e > s) {
            if(vp[s].ff + vp[e].ff == target) {
                return {min(vp[s].ss, vp[e].ss), max(vp[s].ss, vp[e].ss)};
            } else if(vp[s].ff + vp[e].ff > target) {
                --e;
            } else ++s;
        }

        return {};
    }
};
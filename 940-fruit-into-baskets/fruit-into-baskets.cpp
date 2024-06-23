class Solution {
public:
    int totalFruit(vector<int>& v) {
        int l = 0, r = 0;
        map<int, int> mp;
        int n = v.size();
        int maxlen = 0;
        while(r < n) {
            mp[v[r]]++;
            while(mp.size() > 2) {
                mp[v[l]]--;
                if(mp[v[l]] == 0) {
                    mp.erase(v[l]);
                }
                ++l;
            }
            maxlen = max(maxlen, r - l + 1);
            ++r;
        }

        return maxlen;

    }
};
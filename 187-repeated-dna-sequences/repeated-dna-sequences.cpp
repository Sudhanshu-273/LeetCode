class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> mp;
        int l = 0;
        while(l + 10 <= s.length()) {
            string str = s.substr(l, 10);
            mp[str]++;
            ++l;
        }
        vector<string> v;
        for(auto it : mp) {
            if(it.second > 1) {
                v.push_back(it.first);
            }
        }
        return v;
    }
};
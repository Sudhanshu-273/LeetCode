class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        map<string, vector<string>> mp;
        for(int i = 0; i < v.size(); ++i) {
            string str = v[i];
            sort(str.begin(), str.end());
            mp[str].push_back(v[i]);
        }
        vector<vector<string>> ans;
        for(auto it : mp) {

            ans.push_back(it.second);
        }

        return ans;


    }
};
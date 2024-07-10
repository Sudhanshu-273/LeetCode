class Solution {
public:
    int minOperations(vector<string>& s) {
        int count = 0;
        for(auto str : s) {
            if(str[0] == '.') {
                if(str[1] == '.') {
                    count -=1;
                    count = max(count, 0);
                }
            } else {
                count += 1;
            }
        }
        return count;
    }
};
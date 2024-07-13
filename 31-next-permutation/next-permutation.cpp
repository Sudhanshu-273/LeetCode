class Solution {
public:
    void nextPermutation(vector<int>& a) {
        if(a.size() == 1) return;
        int idx = -1, n = a.size();
        for(int i = n - 2; i >= 0; --i) {
            if(a[i] < a[i + 1]) {
                idx = i;
                break;
            }
        }
        if(idx == -1) {
            sort(a.begin(), a.end());
            return;
        }
        for(int i = n - 1; i > idx; --i) {
            if(a[i] > a[idx]) {
                swap(a[i], a[idx]);
                sort(a.begin() + idx + 1, a.end());
                return;
            }
        }
    }
};
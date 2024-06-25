class Solution {
public:
    int checkf(vector<int>& arr) {
        int l = 0, r = 0, n = arr.size();
        int count = 0;
        while (r < n) {
            if(r == n - 1)
                break;

            if(r & 1) {
                if(arr[r] <= arr[r + 1]) {
                    count = max(count, r - l + 1);
                    ++r;
                    l = r;
                } else {
                    count = max(count, r - l + 1);
                    ++r;
                }
            } else {
                if(arr[r] >= arr[r + 1]) {
                    count = max(count, r - l + 1);
                    ++r;
                    l = r;
                } else {
                    count = max(count, r - l + 1);
                    ++r;
                }
            }
        }
        count = max(count, r - l + 1);
        return count;
    }

    int checks(vector<int>& arr) {
        int l = 0, r = 0, n = arr.size();
        int count = 0;
        while (r < n) {
            if(r == n - 1) {
                // count = max(count, r - l + 1);
                break;
            }

            if(r & 1) {
                if(arr[r] >= arr[r + 1]) {
                    count = max(count, r - l + 1);
                    ++r;
                    l = r;
                } else {
                    count = max(count, r - l + 1);
                    ++r;
                }
            } else {
                if(arr[r] <= arr[r + 1]) {
                    count = max(count, r - l + 1);
                    ++r;
                    l = r;
                } else {
                    count = max(count, r - l + 1);
                    ++r;
                }
            }
        }
        count = max(count, r - l + 1);
        return count;
    }

    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1)
            return 1;
        return max(checkf(arr), checks(arr));
    }
};
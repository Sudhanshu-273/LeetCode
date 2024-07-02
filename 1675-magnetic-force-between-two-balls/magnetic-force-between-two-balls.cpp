class Solution {
public:
    int countCows(vector<int>& v, int mid) {
        int count = 1;
        int last = v[0];
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] - last >= mid) {
                ++count;
                last = v[i];
            }
        }
        return count;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        // Write your code here
        int low = 1, high = 1e9;
        int ans = 0;
        while (low <= high) {
            int mid = ((high - low) / 2) + low;
            int count = countCows(position, mid);
            if (count >= m) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return ans;
    }
};
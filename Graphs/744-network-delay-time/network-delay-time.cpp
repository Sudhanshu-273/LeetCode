class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < times.size(); ++i) {
            adj[times[i][0] - 1].push_back({times[i][1] - 1, times[i][2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k - 1});
        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]) {
                if(d + it.second < dist[it.first]) {
                    dist[it.first] = d + it.second;
                    pq.push({d + it.second, it.first});
                }
            }
        }

        int maxi = 0;
        for(int i = 0; i < n; ++i) {
            if(dist[i] == INT_MAX) {
                return -1;
            } 
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};
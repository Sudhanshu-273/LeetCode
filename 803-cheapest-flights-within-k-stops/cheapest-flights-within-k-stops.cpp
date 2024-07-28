class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < flights.size(); ++i) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, src}});
        while(!pq.empty()) {
            int stops = pq.top().first;
            int d = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();

            for(auto it : adj[node]) {
                if(d + it.second < dist[it.first] && stops <= k) {
                    dist[it.first] = it.second + d;
                    pq.push({stops + 1, {dist[it.first], it.first}});
                }
            }
        }

        if(dist[dst] == INT_MAX) {
            return -1;
        }
        return dist[dst];




    }
};
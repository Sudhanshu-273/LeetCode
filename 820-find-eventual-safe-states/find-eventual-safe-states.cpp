class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> ind(n, 0);
        for(int i = 0; i < n; ++i) {
            ind[i] = graph[i].size();
            for(auto it : graph[i]) {
                adj[it].push_back(i);
            }
        }
        queue<int> qe;
        for(int i = 0; i < n; ++i)
            if(!ind[i]) qe.push(i);

        vector<int> ans;
        while(!qe.empty()) {
            int node = qe.front();
            qe.pop();
            ans.push_back(node);
            for(auto it : adj[node]) {
                ind[it]--;
                if(!ind[it]) qe.push(it);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;

    }
};
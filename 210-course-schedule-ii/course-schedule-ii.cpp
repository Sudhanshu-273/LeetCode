class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> ind(n, 0);
        for(int i = 0; i < pre.size(); ++i) {
            adj[pre[i][1]].push_back(pre[i][0]);
            ind[pre[i][0]]++;
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
                if(!ind[it]) {
                    qe.push(it);
                }
            }
        }
        if(ans.size() == n) return ans;
        return {};
        

    }
};
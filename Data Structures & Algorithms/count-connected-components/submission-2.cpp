class Solution {
    void dfs(int node, vector<vector<int>>&adj, unordered_set<int>&vis)
    {
        if(vis.count(node))
        {
            return;
        }

        vis.insert(node);
        for(auto &nbr : adj[node])
        {
            if(vis.count(nbr) == 0)
            {
                dfs(nbr, adj, vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n+1);

        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_set<int>vis;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(vis.count(i) == 0)
            {
                dfs(i, adj, vis);
                count++;
            }
        }
        return count;

    }
};

class Solution {
    int dfs(int node, vector<vector<int>> &adj, unordered_set<int>&vis)
    {
        vis.insert(node);
        int h = 0;

        for(auto &nbr : adj[node])
        {
            if(vis.count(nbr) == 0)
            {
                int sh = dfs(nbr, adj, vis);
                h = max(h, sh);
            }
        }

        return 1 + h;

    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto &edge : edges)
        {
            int u = edge[0], v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, vector<int>> mp;
        int minHeight = n;
        for(int i = 0; i < n; i++)
        {
            unordered_set<int>vis;
            int height = dfs(i, adj, vis);
            minHeight = min(minHeight, height);
            mp[height].push_back(i);
        }

        for(auto &p : mp)
        {
            if(p.first == minHeight)
            {
                return p.second;
            }
        }
        return {};
        
    }
};
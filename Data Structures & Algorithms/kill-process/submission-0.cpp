class Solution {
    void dfs(int node, int parent, unordered_map<int, vector<int>>&adj, unordered_set<int>&vis, vector<int>&ans)
    {
        vis.insert(node);
        ans.push_back(node);

        for(auto nbr : adj[node])
        {
            if(nbr == parent) continue;
            if(!vis.count(nbr))
            {
                dfs(nbr, node, adj, vis, ans);
            }
        }
    }
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        unordered_map<int, vector<int>>adj;

        int parent = 0;
        for(int i = 0; i < n; i++)
        {
            int u = pid[i];
            int v = ppid[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
            if(u == kill)
            {
                parent = ppid[i];
            }
        }

        unordered_set<int>vis;
        vector<int>ans;
        dfs(kill, parent, adj, vis, ans);
        
        return ans;
    }
};

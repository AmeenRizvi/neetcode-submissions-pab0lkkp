class Solution {
    void dfs(int node, vector<vector<int>>&adj, unordered_set<int>&vis)
    {
        vis.insert(node);

        for(auto nbr : adj[node])
        {
            if(!vis.count(nbr))
            {
                dfs(nbr, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n+1);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j && isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }

        unordered_set<int>vis;
        int provinces = 0;
        for(int i = 0; i < n; i++)
        {
            if(!vis.count(i))
            {
                dfs(i, adj, vis);
                provinces++;
            }
        }
        return provinces;
        
    }
};
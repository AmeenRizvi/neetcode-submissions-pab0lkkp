class Solution {
    void dfs(int node, vector<vector<int>>&adj, unordered_set<int>&vis)
    {
        vis.insert(node);
        for(auto nbr : adj[node])
        {
            if(vis.count(nbr) == 0)
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
                if(isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                }
            }
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
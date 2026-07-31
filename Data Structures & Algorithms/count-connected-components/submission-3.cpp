class Solution {
    void bfs(int node, vector<vector<int>>&adj, unordered_set<int>&vis)
    {
        queue<int>q;
        q.push(node);
        vis.insert(node);

        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            for(auto &nbr : adj[front])
            {
                if(vis.count(nbr) == 0)
                {
                    q.push(nbr);
                    vis.insert(nbr);
                }
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
                bfs(i, adj, vis);
                count++;
            }
        }
        return count;

    }
};

class Solution {
    int dfs(int node, int parent, vector<vector<int>>&adj)
    {
        int h = 0;
        for(int nbr : adj[node])
        {
            if(nbr == parent)
            {
                continue;
            }
            h = max(h, 1 + dfs(nbr, node, adj));
        }
        return h;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
        {
            return {0};
        }
        vector<vector<int>>adj(n);

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>edgeCnt(n);
        queue<int>leaves;
        for(int i = 0; i < n; i++)
        {
            edgeCnt[i] = adj[i].size();
            if(adj[i].size() == 1)
            {
                leaves.push(i);
            }
        }

        while(!leaves.empty())
        {
            if(n <= 2)
            {
                vector<int>res;
                while(!leaves.empty())
                {
                    res.push_back(leaves.front());
                    leaves.pop();
                }
                return res;
            }
            int sz = leaves.size();
            for(int i = 0; i < sz; i++)
            {
                int front = leaves.front();
                leaves.pop();
                n--;

                for(int nbr : adj[front])
                {
                    edgeCnt[nbr]--;
                    if(edgeCnt[nbr] == 1)
                    {
                        leaves.push(nbr);
                    }
                }

            }
        }
        return {};


    }
};
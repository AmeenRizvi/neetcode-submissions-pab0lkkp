class Solution {
    bool dfs(int node, vector<vector<int>>&adj, unordered_set<int>&vis, unordered_set<int>&dfsVis  )
    {
        vis.insert(node);
        dfsVis.insert(node);

        for(auto nbr : adj[node])
        {
            if(!vis.count(nbr))
            {
                if( dfs(nbr, adj, vis, dfsVis) )
                    return true;
            }
            else if(dfsVis.count(nbr))
            {
                return true;
            }
        }
        dfsVis.erase(node);
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto &p : prerequisites)
        {
            int u = p[0];
            int v = p[1];

            adj[u].push_back(v);
        }

        unordered_set<int>vis;
        for(int i = 0; i < numCourses; i++)
        {
            unordered_set<int>dfsVis;
            if(!vis.count(i))
            {
                bool cycle = dfs(i, adj, vis, dfsVis);
                if(cycle) return false;
            }
        }
        return true;
    }
};

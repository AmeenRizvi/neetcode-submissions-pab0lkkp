class Solution {
    unordered_set<int>vis;
    unordered_set<int>dfsVis;

    bool dfs(int node, vector<vector<int>>&adj)
    {
        vis.insert(node);
        dfsVis.insert(node);

        for(auto &nbr : adj[node])
        {
            if(vis.count(nbr) == 0)
            {
                if( dfs(nbr, adj) )
                {
                    return true;
                }
            }
            else if(dfsVis.count(nbr))
            {
                return true;  // cycle exists
            }
        }
        dfsVis.erase(node);
        return false;  // no cycle
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto &pre : prerequisites)
        {
            int u = pre[0];
            int v = pre[1];

            adj[u].push_back(v);
        }

        for(int i = 0; i < numCourses; i++)
        {
            if(vis.count(i) == 0)
            {
                bool cycle = dfs(i, adj);
                if(cycle) return false;   // Not possible to finish all courses
            }
        }
        return true;   // all courses can be finished
        
    }
};

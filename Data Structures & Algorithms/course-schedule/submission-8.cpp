class Solution {
    unordered_set<int>vis;
    unordered_set<int>dfsVis;

    bool dfs(int node, vector<vector<int>>&adj)
    {
        if(dfsVis.count(node) )  // cycle exists
        {
            return true;
        }
        if(vis.count(node) )
        {
            return false;
        }


        vis.insert(node);
        dfsVis.insert(node);

        for(auto &nbr : adj[node])
        {
            if( dfs(nbr, adj) )
            {
                return true;
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

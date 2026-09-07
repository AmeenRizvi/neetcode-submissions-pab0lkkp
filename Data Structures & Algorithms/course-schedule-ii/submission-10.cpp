class Solution {
    bool dfsCyclic(int node, vector<vector<int>>&adj, 
    unordered_set<int>&vis, unordered_set<int>&dfsVis, vector<int>&ans)
    {
        vis.insert(node);
        dfsVis.insert(node);

        for(auto &nbr : adj[node])
        {
            if(vis.count(nbr) == 0)
            {
                if( dfsCyclic(nbr, adj, vis, dfsVis, ans) )
                {
                    return true;
                }
            }
            else if(dfsVis.count(nbr))   // node is both vis and dfsVis -> there is a cycle
            {
                return true;
            }
        }

        dfsVis.erase(node);    // node gets removed from dfs path
        ans.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto &pre : prerequisites)
        {
            int u = pre[0], v = pre[1];

            // directed graph
            adj[u].push_back(v);
        }


        unordered_set<int>vis;    // track visited nodes
        unordered_set<int>dfsVis; // track nodes in dfs path

        vector<int>ans;   // to store result

        for(int i = 0; i < numCourses; i++)
        {
            if(vis.count(i) == 0)
            {
                bool cycle = dfsCyclic(i, adj, vis, dfsVis, ans);
                // if DAG is cyclic, it is not possible to finish all the courses
                if(cycle)
                {
                    return {};
                }
            }
        }
        // no cycle, we can finish all courses
        return ans;
        
    }
};

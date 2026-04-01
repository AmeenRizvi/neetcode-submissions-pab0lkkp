class Solution {
    bool dfsCycle(int node, vector<vector<int>>&adjList, unordered_set<int>&vis, 
    unordered_set<int>&dfsVis, vector<int>&ans )
    {
        vis.insert(node);
        dfsVis.insert(node);

        for(auto nbr : adjList[node])
        {
            if(!vis.count(nbr))
            {
                if(dfsCycle(nbr, adjList, vis, dfsVis, ans))
                {
                    return true;
                }
            }
            else if(dfsVis.count(nbr))
            {
                return true;
            }
        }

        dfsVis.erase(node);
        ans.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adjList(numCourses);

        for(auto &pre : prerequisites)
        {
            int u = pre[0];
            int v = pre[1];

            adjList[u].push_back(v);
        }

        unordered_set<int>vis;
        unordered_set<int>dfsVis; // directed graph, we need another data structue
                                // for nodes in DFS Path 

        // if cycle found - false - not psbl to take all courses
        // if cycle not found - true ; psbl to take courses
        vector<int>ans;

        for(int i = 0; i < numCourses; i++)
        {
            if(!vis.count(i))
            {
                if(dfsCycle(i, adjList, vis, dfsVis, ans))
                {
                    return {};
                }
            }
        }
        
        return ans;
        
    }
};

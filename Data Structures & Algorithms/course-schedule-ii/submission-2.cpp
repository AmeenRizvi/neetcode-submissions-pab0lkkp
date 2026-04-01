class Solution {
    bool dfs(int node, unordered_set<int>&vis, unordered_set<int>&dfsVis,
    vector<int>&res, unordered_map<int, vector<int>> &adjList)
    {
        vis.insert(node);
        dfsVis.insert(node);
        for(auto nbr : adjList[node])
        {
            if(!vis.count(nbr))
            {
                if( dfs(nbr, vis, dfsVis, res, adjList) )
                    return true;
            }
            else if(dfsVis.count(nbr))
            {
                return true;
            }
        }
        dfsVis.erase(node);
        res.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>adjList;
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjList[u].push_back(v);
        }

        unordered_set<int>vis;
        unordered_set<int>dfsVis;
        vector<int>res;

        for(int i = 0; i < numCourses; i++)
        {
            if(!vis.count(i))
            {
                if( dfs(i, vis, dfsVis, res, adjList) )
                    return {};
            }
            
        }
        return res;
        
    }
};

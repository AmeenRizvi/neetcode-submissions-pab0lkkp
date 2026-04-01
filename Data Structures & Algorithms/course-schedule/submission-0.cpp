class Solution {
    bool dfs(int node, unordered_map<int, list<int>>&adjList, unordered_set<int>&vis,
     unordered_set<int>&dfsPath )
    {
        vis.insert(node);
        dfsPath.insert(node);

        for(auto nbr : adjList[node])
        {
            if(vis.find(nbr) == vis.end())
            {
                if(dfs(nbr, adjList, vis, dfsPath))
                    return true;
            }
            else if(dfsPath.find(nbr) != dfsPath.end())
            {
                return true;
            }
        }

        dfsPath.erase(node);
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>>adjList;
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[u].push_back(v);
        }

        unordered_set<int>vis;
        unordered_set<int>dfsPath;

        for(int i = 0; i < numCourses; i++)
        {
            if(adjList.find(i) != adjList.end() && vis.find(i) == vis.end())
            {
                if(dfs(i, adjList, vis, dfsPath) )
                    return false; // cycle present
            }
        }

        return true; // cycle not present



        
    }
};

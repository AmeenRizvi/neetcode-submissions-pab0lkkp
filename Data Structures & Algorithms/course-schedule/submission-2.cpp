class Solution {
    bool dfs(int node, unordered_map<int, vector<int>>&adjList, unordered_set<int>&vis,
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
        unordered_map<int, vector<int>>adjList;
        vector<int>indegree(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            indegree[v]++;
            adjList[u].push_back(v);
        }

        // unordered_set<int>vis;
        // unordered_set<int>dfsPath;

        // for(int i = 0; i < numCourses; i++)
        // {
        //     if(adjList.find(i) != adjList.end() && vis.find(i) == vis.end())
        //     {
        //         if(dfs(i, adjList, vis, dfsPath) )
        //             return false; // cycle present
        //     }
        // }

        // return true; // cycle not present

        queue<int>q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        int finish = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            finish++;
            for(auto nbr : adjList[node])
            {
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
        return finish == numCourses;





        
    }
};

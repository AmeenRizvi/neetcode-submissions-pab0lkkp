class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Kahn's Algorithm
        vector<vector<int>>adjList(numCourses);
        vector<int>inDegree(numCourses);

        for(auto &pre : prerequisites)
        {
            int u = pre[0];
            int v = pre[1];

            adjList[u].push_back(v);
            inDegree[v]++;
        }

        
        queue<int>q;
        for(int i = 0; i < numCourses; i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        // to check cycle - find TopoSort order
        vector<int>topoSort;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            topoSort.push_back(front);

            for(auto nbr : adjList[front])
            {
                inDegree[nbr]--;
                if(inDegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }

        return topoSort.size() == numCourses;
        // if topoSort size == numCourses, there is no cycle, 
        //can take all courses, return true

        // if topoSrot size != numCourses, there is cycle
        // cannot take all courses, return false
        
    }
};

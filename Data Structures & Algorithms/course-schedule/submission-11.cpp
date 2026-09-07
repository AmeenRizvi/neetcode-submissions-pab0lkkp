class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Kahn's algorithm
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);

        for(auto &pre : prerequisites)
        {
            int u = pre[0];
            int v = pre[1];

            adj[u].push_back(v);    // adjaceny list
            indegree[v]++;          // indegree
        }

        queue<int>q;
        int count = 0;

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                count++;
            }
        }

        while(!q.empty() )
        {
            int front = q.front();
            q.pop();

            for(auto &nbr : adj[front])
            {
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                {
                    q.push(nbr);
                    count++;
                }
            }
        }
        return numCourses == count;
        
    }
};

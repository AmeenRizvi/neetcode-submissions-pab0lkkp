class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int>ans;

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                count++;
                ans.push_back(i);
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
                    ans.push_back(nbr);
                }
            }
        }
        if( numCourses != count )
        {
            return {};
        }

        reverse(ans.begin(), ans.end());
        return ans;
        
        
    }
};

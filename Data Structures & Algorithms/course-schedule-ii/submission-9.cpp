class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses, 0);
        vector<vector<int>>adj(numCourses);

        for(auto &pre : prerequisites)
        {
            int u = pre[0];
            int v = pre[1];

            indegree[v]++;
            adj[u].push_back(v);
        }

        queue<int>q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int count = 0;
        vector<int>ans;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            count++;
            ans.push_back(front);

            for(auto nbr : adj[front])
            {
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        if( count == numCourses )
        {
            return ans;
        }
        return {};
    }
};

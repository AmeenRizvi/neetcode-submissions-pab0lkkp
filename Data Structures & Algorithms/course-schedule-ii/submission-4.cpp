class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto &p : prerequisites)
        {
            int u = p[0];
            int v = p[1];

            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int>q;
        vector<int>ans(numCourses);

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int finish = 0;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            ans[numCourses - finish -1] = front;
            finish++;

            for(auto nbr : adj[front])
            {
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
        if (finish == numCourses) 
            return ans;
        return {};
        
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);

        for(auto &p : prerequisites)
        {
            int u = p[0];
            int v = p[1];

            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int>q;
        vector<int>ans;

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            for(auto nbr : adj[front])
            {
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                {
                    q.push(nbr);
                    ans.push_back(nbr);
                }
            }
        }
        return ans.size() == numCourses;
    }
};

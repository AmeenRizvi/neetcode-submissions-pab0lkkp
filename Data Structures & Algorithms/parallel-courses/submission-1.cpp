class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>>adjList(n+1);
        vector<int>inDegree(n+1);

        for(int i = 0; i < relations.size(); i++)
        {
            int u = relations[i][0];
            int v = relations[i][1];

            adjList[u].push_back(v);
            inDegree[v]++;
        }

        queue<int>q;
        for(int i = 1; i <= n; i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        if(q.empty()) return -1;

        int semester = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                int front = q.front();
                q.pop();
                for(auto nbr : adjList[front])
                {
                    inDegree[nbr]--;
                    if(inDegree[nbr] == 0)
                    {
                        q.push(nbr);
                    }
                }
            }
            semester++;
        }

        for(int i = 1; i <= n; i++)
        {
            if(inDegree[i] != 0)
            {
                return -1;
            }
        }
        return semester;

        
        
    }
};

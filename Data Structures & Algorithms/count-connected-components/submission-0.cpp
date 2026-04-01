class Solution {
    void dfs(int node, vector<vector<int>>&adjList,unordered_set<int>&vis )
    {
        vis.insert(node);
        for(int nbr : adjList[node])
        {
            if(vis.find(nbr) == vis.end())
            {
                dfs(nbr, adjList, vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(n);

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int count = 0;
        unordered_set<int>vis;

        for(int i = 0; i < n; i++)
        {
            if( vis.find(i) == vis.end())
            {
                dfs(i, adjList, vis);
                count++;
            }
        }
        return count;



    }
};

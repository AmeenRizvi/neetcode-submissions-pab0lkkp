class Solution {
    static const int gray = 1;
    static const int black = 2;

    bool dfs(int node, int destination, vector<vector<int>>&adjList, vector<int>&states )
    {
        if(states[node] != 0)
            return states[node] == black;
        
        if(adjList[node].size() == 0)
            return node == destination;
        
        states[node] = gray;
        for(auto nbr : adjList[node])
        {
            if(!dfs(nbr, destination, adjList, states))
            {
                return false;
            }
        }

        states[node] = black;
        return true;

    }
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adjList(n);

        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
        }

        vector<int>states(n, 0);
        return dfs(source, destination,  adjList, states);

        
    }
};

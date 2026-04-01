class Solution {
    unordered_set<int>vis;

    bool hasCycle(int node, int parent, unordered_map<int, vector<int>>adjList)
    {

        vis.insert(node);
        for(auto nbr : adjList[node])
        {
            
            if(vis.find(nbr) == vis.end())
            {
                if(hasCycle(nbr, node, adjList))
                    return true;
            }
            else if(nbr != parent)
                return true;
            
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n-1)
            return false;

        unordered_map<int, vector<int>>adjList;

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }               
            
        if(hasCycle(0,-1, adjList))
            return false;
            
        return vis.size() == n;


    }
};

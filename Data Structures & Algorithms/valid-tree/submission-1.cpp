class Solution {
    unordered_set<int>vis;

    bool dfs(int node, int parent, unordered_map<int, vector<int>>adjList)
    {
        if(vis.count(node))
            return false;

        vis.insert(node);
        for(auto nbr : adjList[node])
        {
            if(nbr == parent)
                continue;
            
            
            if(!dfs(nbr, node, adjList))
                return false;
            
            
            
        }
        return true;
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

        
        
            
                
            
                if(!dfs(0,-1, adjList))
                    return false;
            
        

        return vis.size() == n;


    }
};

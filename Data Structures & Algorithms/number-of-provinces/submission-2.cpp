class Solution {
    void dfs(int node, vector<vector<int>>& isConnected, unordered_set<int>&vis)
    {
        vis.insert(node);
        for(int nbr = 0; nbr < isConnected[node].size(); nbr++)
        {
            if(isConnected[node][nbr] == 1 && vis.count(nbr) == 0)
            {
                dfs(nbr, isConnected, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_set<int>vis;
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if(vis.count(i) == 0)
            {
                dfs(i, isConnected, vis);
                count++;
            }
        }

        return count;
        
    }
};
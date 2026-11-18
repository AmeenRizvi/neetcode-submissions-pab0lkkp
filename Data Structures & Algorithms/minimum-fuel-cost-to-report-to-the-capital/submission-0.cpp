class Solution {
private:
    pair<long long, long long>dfs(int node, vector<vector<int>>&adj, unordered_set<int>&vis, int seats)
    {
        vis.insert(node);
        long long pass = 1, fuel = 0;

        for(auto &nbr : adj[node])
        {
            if(!vis.count(nbr))
            {
                pair<long long, long long>temp = dfs(nbr, adj, vis, seats);
                pass += temp.first;
                fuel += temp.second;
            }
        }

        if(node != 0)
        {
            fuel += ceil((double)pass/seats);

        }

        return {pass, fuel};
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        vector<vector<int>>adj(n);

        for(auto &road : roads)
        {
            int u = road[0], v = road[1];

            adj[u].push_back(v);
            adj[v].push_back(u); 
        }

        unordered_set<int>vis;
        pair<long long, long long> ans =dfs(0, adj, vis, seats);
        return ans.second;

    }
};

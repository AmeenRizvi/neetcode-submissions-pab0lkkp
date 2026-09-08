class Solution {
    double dfs(string node, string v, 
    unordered_map<string, vector<pair<string, double>> >&adj, unordered_set<string>&vis)
    {
        if(adj.count(node) == 0 || adj.count(v) == 0)
        {
            return -1.0;
        }

        if(node == v)
        {
            return 1.0;
        }

        vis.insert(node);

        for(auto &nbr : adj[node])
        {
            string v2 = nbr.first;
            double w = nbr.second;

            if(vis.count(v2) == 0)
            {
                double tmp = dfs(v2, v, adj, vis);
                if(tmp != -1.0)
                {
                    return w*tmp;
                }
            }
        }

        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>> >adj;
        int n = equations.size();

        for(int i = 0; i < n; i++ )
        {
            string u = equations[i][0], v = equations[i][1];
            double w = values[i];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 1/w});
        }

        int m = queries.size();
        vector<double>res;

        for(int j = 0; j < m; j++)
        {
            string u = queries[j][0], v = queries[j][1];

            unordered_set<string>vis;
            double ans = dfs(u, v, adj, vis);
            res.push_back(ans);
        }
        return res;
        
    }
};
class Solution {
    int solve(vector<vector<int>>& costs, int idx, int prev_color_i, vector<vector<int>>&dp)
    {
        if(idx >= costs.size())
        {
            return 0;
        }
        if(dp[idx][prev_color_i + 1] != -1)
        {
            return dp[idx][prev_color_i + 1];
        }
        
        int minCost = INT_MAX;
        for(int i = 0; i < 3; i++)
        {
            if(prev_color_i == -1 || i != prev_color_i)
            {
                int temp = solve(costs, idx+1, i, dp) + costs[idx][i];
                minCost = min(minCost, temp);
            }
        }
        return dp[idx][prev_color_i + 1] = minCost;
    }
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>>dp(n+1, vector<int>(4, -1));

        return solve(costs, 0, -1, dp);
        
    }
};
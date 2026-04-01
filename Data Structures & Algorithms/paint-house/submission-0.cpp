class Solution {
    int solve(int iH, int iC, vector<vector<int>>& costs, vector<vector<int>>&dp )
    {
        if(iH >= costs.size())
        {
            return 0;
        }
        if(dp[iH][iC+1] != -1)
        {
            return dp[iH][iC+1];
        }

        int minCost = INT_MAX;
        for(int i = 0; i < 3; i++)
        {
            if(i != iC)
            {
                minCost = min(minCost, costs[iH][i] + solve(iH+1, i, costs, dp));
            }
        }
        return dp[iH][iC+1] = minCost;
    }
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>>dp(n, vector<int>(4, -1));
        return solve(0, -1, costs, dp);
        
    }
};
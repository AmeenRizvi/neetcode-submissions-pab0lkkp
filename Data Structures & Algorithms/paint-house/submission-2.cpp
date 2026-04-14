class Solution {
    vector<vector<int>>dp;
    
    int solve(int n, int prev_j,  vector<vector<int>>& costs)
    {
        if(n < 0) return 0;
        if(dp[n][prev_j + 1] != -1)
            return dp[n][prev_j + 1];

        int ans = INT_MAX;
        for(int j = 0; j < 3; j++)
        {
            if(j != prev_j)
            {
                ans = min(ans, costs[n][j] + solve(n-1, j, costs));
                
            }
        }

        return dp[n][prev_j + 1] = ans;
    }
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        dp.resize(n, vector<int>(4, -1));
        return solve(n-1, -1, costs) ;
    }
};
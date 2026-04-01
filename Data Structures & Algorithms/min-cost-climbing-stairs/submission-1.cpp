class Solution {
    int solve(int n, vector<int>& cost, vector<int>&dp)
    {
        if(n < 0)
        {
            return 0;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        int p1 = solve(n-1, cost, dp);
        int p2 = solve(n-2, cost, dp);
        return dp[n] = cost[n] +  min(p1, p2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);
        return solve(n, cost, dp);
        
    }
};

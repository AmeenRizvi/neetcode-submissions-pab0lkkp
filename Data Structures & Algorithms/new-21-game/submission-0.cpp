class Solution {
    double solve(int p, int n, int k, int maxPts, vector<double>&dp)
    {
        if(p >= k)
        {
            return p <= n ? 1.0 : 0.0;
        }
        if(dp[p] != -1.0)
        {
            return dp[p];
        }

        double ans = 0.0;
        for(int i = 1; i <= maxPts; i++)
        {    
            ans += solve(p+i, n, k, maxPts, dp);   
        }
        return dp[p] = ans/maxPts;
    }
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double>dp(k+1, -1.0);
        return solve(0, n, k, maxPts, dp);
    }
};
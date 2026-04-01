class Solution {
    int solve(int i, int n, vector<int>&dp)
    {
        if(i == n)
            return 1;
        if(i > n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int p1 = solve(i+1, n, dp);
        int p2 = solve(i+2, n, dp);

        return dp[i] = p1 + p2;
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return solve(0, n, dp);
        
    }
};

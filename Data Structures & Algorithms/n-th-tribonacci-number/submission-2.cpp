class Solution {
    int solve(int n, vector<int>&dp)
    {
        if(n <= 1)
        {
            return n;
        }
        if(n == 2)
        {
            return 1;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }

        int val = solve(n-1, dp) + solve(n-2, dp) + solve(n-3, dp);
        return dp[n] = val;
    }
public:
    int tribonacci(int n) {
        vector<int>dp(n+1, -1);
        return solve(n, dp);
        
    }
};
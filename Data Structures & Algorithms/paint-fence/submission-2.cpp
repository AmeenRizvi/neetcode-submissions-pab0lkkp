class Solution {
    // unordered_map<int,int>dp;
    int solve(int n, int k, vector<int>&dp)
    {
        if(n == 1) return k;
        if(n == 2) return k*k;
        if(dp[n] != -1) return dp[n];

        int op1 = solve(n-1, k, dp);
        int op2 = solve(n-2, k, dp);

        return dp[n] = (k-1)*(op1 + op2);
    }
public:
    int numWays(int n, int k) {
        vector<int>dp(n+1, -1);
        return solve(n, k, dp);
        
    }
};

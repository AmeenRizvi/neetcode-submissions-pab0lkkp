class Solution {
    int solve(int n, vector<int>&dp)
    {
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];

        int ans = 1;
        for(int i = n-1; i >= 2; i--)
        {
            int temp = i*max(n-i, solve(n-i, dp) );
            ans = max(ans, temp);
        }
        return dp[n] = ans;
    }
public:
    int integerBreak(int n) {
        vector<int>dp(n+1, -1);
        return solve(n, dp);
        
    }
};
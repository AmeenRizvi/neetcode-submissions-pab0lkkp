class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1, 0);
        // return solve(n, dp);
        dp[1] = 1;

        for(int i = 2; i <= n; i++)
        {
            int ans = 1;
            for(int j = i-1; j >= 1; j--)
            {
                int temp = j*max(i-j, dp[i-j]);
                ans = max(ans, temp);
            }
            dp[i] = ans;
        }
        return dp[n];
        
    }
};
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(amount+1, vector<int>(n+1, 0));
        // return solve(n-1, amount, coins, dp);
        // vector<int>dp(amount+1, 0);

        for(int i = 0; i <= n; i++)
        {
            dp[0][i] = 1;
        }
        
        for(int a = 1; a <= amount ; a++ )
        {
            for(int i = 0; i < n; i++)
            {
                dp[a][i+1] = dp[a][i];
                if(a-coins[i] >= 0)
                {
                    dp[a][i+1] += dp[a - coins[i]][i+1];
                }
            }
        }
        return dp[amount][n];
        
    }
};

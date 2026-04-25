class Solution {
    int solve(int amount, vector<int>& coins, vector<int>&dp)
    {
        if(amount < 0)
        {
            return -1;
        }
        if(amount == 0)
        {
            return 0;
        }
        if(dp[amount] != -1)
        {
            return dp[amount];
        }

        int minCoins = 1e9;
        for(int i = 0; i < coins.size(); i++)
        {
            int coinsInPath = solve(amount - coins[i], coins, dp);
            if(coinsInPath != -1)
                minCoins = min(minCoins, 1 + coinsInPath );
        }
        return dp[amount] =  minCoins >= 1e9 ? 1e9 : minCoins;

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount + 1, 1e9);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++)
        {
            int minCoinsInPath = 1e9;
            for(int j = 0; j < coins.size(); j++)
            {
                if(i - coins[j] >= 0)
                {
                    minCoinsInPath = min(minCoinsInPath, dp[i - coins[j] ] );
                }
            }
            dp[i] = 1 + minCoinsInPath;
        }

        return dp[amount] >= 1e9 ? -1 : dp[amount];

        
    }
};

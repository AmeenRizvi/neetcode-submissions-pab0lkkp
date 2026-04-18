class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount + 1, 1e9);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++)
        {
            int minCoins = 1e9;
            for(int coin : coins)
            {
                if(i - coin >= 0)
                {
                    minCoins = min(minCoins,1 + dp[ i-coin ]);
                }
            }

            dp[i] = minCoins;
        }

        return dp[amount] >= 1e9 ? -1 : dp[amount];
    }
};

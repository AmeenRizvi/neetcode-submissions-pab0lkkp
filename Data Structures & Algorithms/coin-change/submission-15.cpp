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
        vector<int>dp(amount + 1, -1);

        int ans = solve(amount, coins, dp);
        return ans >= 1e9 ? -1 : ans;
        
    }
};

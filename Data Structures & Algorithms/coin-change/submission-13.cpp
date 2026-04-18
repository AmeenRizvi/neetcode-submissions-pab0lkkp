class Solution {
    int solve(int amount, vector<int>& coins, vector<int>&dp)
    {
        if(amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];
        
        int minCoins = 1e9;
        for(int coin : coins)
        {
            if(amount - coin >= 0)
            {
                minCoins = min(minCoins, 1 + solve(amount - coin, coins, dp) );
            }
        }
        return dp[amount] = minCoins;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount + 1, -1);

        int ans = solve(amount, coins, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};

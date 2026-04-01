class Solution {
    int solve(int amount, vector<int>& coins, vector<int>&dp)
    {
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        if(dp[amount] != -2) return dp[amount];

        int minCoins = INT_MAX;
        for(int i = 0; i < coins.size(); i++)
        {
            int tmp = solve(amount-coins[i], coins, dp);
            if(tmp != -1)
                minCoins = min(minCoins, tmp);
        }
        return dp[amount] = minCoins == INT_MAX ? -1 : minCoins+1;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1, -2);
        return solve(amount, coins, dp);
        
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1, amount+1);
        dp[amount] = 0;

        for(int i = amount; i >= 0; i--)
        {
            int minCoins = INT_MAX;
            for(int j = 0; j < n; j++)
            {
                if(i + coins[j] <= amount)
                {
                    if((long long)i+coins[j] > INT_MAX)
                        continue;
                    minCoins = min(minCoins, 1+dp[i+coins[j]]);
                    if(minCoins != INT_MAX)
                        dp[i] = minCoins;
                }
            }
        }
        return dp[0] > amount ? -1 : dp[0];
    }
};

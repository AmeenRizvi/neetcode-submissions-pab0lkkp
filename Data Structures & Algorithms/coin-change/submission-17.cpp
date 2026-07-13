class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, 1e9);
        dp[0] = 0;

        for(int a = 1; a <= amount; a++)
        {
            int minCoins = 1e9;
            for(int c : coins)
            {
                if(a - c >= 0)
                {
                    int temp = dp[a-c];
                    minCoins = min(minCoins, temp);
                }
            }
            dp[a] = minCoins >= 1e9 ? 1e9 : minCoins + 1;
        }
        return dp[amount] >= 1e9 ? -1 : dp[amount];
        
    }
};

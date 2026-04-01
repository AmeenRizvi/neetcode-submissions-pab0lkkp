class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1, amount+1);
        dp[amount] = 0;

        for(int i = amount-1; i >= 0; i--)
        {
            for(int num : coins)
            {
                if((long long)i+num > amount)
                    continue;
                if(i+num <= amount)
                    dp[i] = min(dp[i], dp[i+num]+1);
            }
        }
        return dp[0] == amount+1 ? -1 : dp[0];
        
    }
};

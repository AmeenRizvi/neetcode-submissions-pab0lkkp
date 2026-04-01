class Solution {
    int solve(int sum, vector<int>& coins, int amount, vector<int>&dp )
    {
        if(sum == amount)
        {
            return 0;
        }
        if(sum > amount)
        {
            return -1;
        }
        if(dp[sum] != -2)
        {
            return dp[sum];
        }

        int minCoins = INT_MAX;
        for(int i = 0; i < coins.size(); i++)
        {
            if((long long)sum + coins[i] > amount )
            {
                continue;
            }
            int temp = solve(sum+coins[i], coins, amount, dp);
            if(temp != -1)
            {
                minCoins = min(minCoins, temp);
            }
        }
        return dp[sum] = minCoins == INT_MAX ? -1 : 1 + minCoins;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, -2);
        return solve(0, coins, amount, dp);
        
    }
};

class Solution {
    int solve(int sum, int amount, vector<int>& coins, vector<int>&dp)
    {
        if(sum == amount)
            return 0;
        if(sum > amount)
            return -1;
        if(dp[sum] != -2)
            return dp[sum];

        int minCoins = INT_MAX;
        for(int num : coins)
        {
            if((long long)sum + num > amount)
                continue;
            int temp = solve(sum + num, amount, coins, dp);
            if(temp != -1)
                minCoins = min(minCoins, temp);
        }
        dp[sum] = minCoins == INT_MAX ? -1 : 1 + minCoins;
        return dp[sum];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, -2);
        return solve(0, amount, coins, dp);
        
    }
};

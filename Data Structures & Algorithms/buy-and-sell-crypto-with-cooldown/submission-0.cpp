class Solution {
    int solve(int i, vector<int>& prices, bool canBuy, vector<vector<int>>&dp)
    {
        if(i >= prices.size()) return 0;
        if(dp[i][canBuy] != -1) return dp[i][canBuy];

        if(canBuy)
        {
            int buy = -prices[i] + solve(i+1, prices, !canBuy, dp);
            int dontBuy = solve(i+1, prices, canBuy, dp);

            return dp[i][canBuy] = max(buy, dontBuy);
        }
        else
        {
            int sell = prices[i] + solve(i+2, prices, !canBuy, dp);
            int dontSell = solve(i+1, prices, canBuy, dp);

            return dp[i][canBuy] = max(sell, dontSell);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return solve(0, prices, true, dp);
        
    }
};

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
        // vector<vector<int>>dp(n+2, vector<int>(2, 0));
        // return solve(0, prices, true, dp);
        int dp1_buy = 0, dp2_buy = 0;
        int dp1_sell = 0;


        for(int i = n-1; i >= 0; i--)
        {
            int dp_buy = max(dp1_sell - prices[i], dp1_buy);
            int dp_sell = max(dp2_buy + prices[i], dp1_sell);

            dp2_buy = dp1_buy;
            dp1_buy = dp_buy;
            dp1_sell = dp_sell;
            
        }
        return dp1_buy;
        
    }
};

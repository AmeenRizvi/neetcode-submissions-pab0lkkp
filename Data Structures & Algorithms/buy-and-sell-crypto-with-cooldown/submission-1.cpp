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
        vector<vector<int>>dp(n+2, vector<int>(2, 0));
        // return solve(0, prices, true, dp);


        for(int i = n-1; i >= 0; i--)
        {
            for(int canBuy = 1; canBuy >= 0; canBuy--)
            {
                if(canBuy)
                {
                    int buy = -prices[i] + dp[i+1][canBuy-1];
                    int dontBuy = dp[i+1][canBuy];

                    dp[i][canBuy] = max(buy, dontBuy);
                }
                else
                {
                    int sell = prices[i] + dp[i+2][canBuy+1];
                    int dontSell = dp[i+1][canBuy];

                    dp[i][canBuy] = max(sell, dontSell);
                }
            }
        }
        return dp[0][1];
        
    }
};

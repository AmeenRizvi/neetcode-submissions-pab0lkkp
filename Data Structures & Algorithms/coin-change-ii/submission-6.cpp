class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
      
        // vector<int>row(amount+1, 0);
        // vector<int>nextRow(amount+1, 0);

        // row[0] = 1;
        // nextRow[0] = 1;
        vector<int>dp(amount+1, 0);
        dp[0] = 1;

        for(int i = n-1; i >= 0; i--)
        {
            for(int a = 1; a <= amount; a++)
            {
                dp[a] = dp[a] + (coins[i] <= a ? dp[a-coins[i]] : 0 );
            }
        }
        return dp[amount];
    }
};

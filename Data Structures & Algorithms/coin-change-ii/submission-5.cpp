class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>>dp(n+1, vector<int>(amount+1, 0));
        vector<int>row(amount+1, 0);
        vector<int>nextRow(amount+1, 0);

        // for(int i = 0; i <= n; i++)
        // {
        //     dp[i][0] = 1;
        // }
        row[0] = 1;
        nextRow[0] = 1;

        for(int i = n-1; i >= 0; i--)
        {
            for(int a = 1; a <= amount; a++)
            {
                int take = 0;
                if(a >= coins[i])
                {
                    take = row[a - coins[i]];
                }
                int dontTake = nextRow[a];
                
                row[a] = take + dontTake;
            }
            nextRow = row;
        }
        return nextRow[amount];
    }
};

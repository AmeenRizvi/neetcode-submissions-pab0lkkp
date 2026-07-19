class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>>dp(m, vector<int>(n, 0));
        // vector<int>row(n, 0);
        // vector<int>prevRow(n, 0);
        vector<int>dp(n, 0);

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[j] = grid[i][j];
                }
                else
                {
                    int op1 = i-1 < 0 ? INT_MAX : dp[j];
                    int op2 = j-1 < 0 ? INT_MAX : dp[j-1];

                    dp[j] = min(op1, op2) + grid[i][j];
                }
            }
        }
        return dp[n-1];
        
    }
};
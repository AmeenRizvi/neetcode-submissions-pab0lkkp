class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, INT_MAX));
        // for(int i = 0; i < m; i++)
        // {
        //     dp[i][n-1] = INT_MAX;
        // }
        // for(int j = 0; j < n; j++)
        // {
        //     dp[m-1][j] = INT_MAX;
        // }

        dp[m-1][n] = 0;

        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                
                int p1 = dp[i+1][j];
                int p2 = dp[i][j+1];

                dp[i][j] = min(p1, p2) + grid[i][j];
            }
        }
        return dp[0][0];
        
    }
};
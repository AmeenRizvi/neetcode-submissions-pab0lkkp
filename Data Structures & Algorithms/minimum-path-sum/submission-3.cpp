class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

        for(int i = 0; i <= m; i++)
        {
            dp[i][n] = INT_MAX;
        }
        for(int j = 0; j <= n; j++ )
        {
            dp[m][j] = INT_MAX;
        }

        dp[m-1][n-1] = grid[m-1][n-1];

        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(i == m-1 && j == n-1)
                {
                    continue;
                }
                int down = dp[i+1][j];
                int right = dp[i][j+1];

                dp[i][j] = min(down, right) + grid[i][j];
            }
        }
        return dp[0][0];
        
    }
};
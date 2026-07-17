class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++ )
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int p1 = i-1 < 0 ? 0 : dp[i-1][j];
                    int p2 = j-1 < 0 ? 0 : dp[i][j-1];

                    dp[i][j] = p1 + p2;
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};

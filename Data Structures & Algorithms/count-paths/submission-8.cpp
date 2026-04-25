class Solution {
public:
    int uniquePaths(int m, int n) {
        // Bottom up tabulation approach
        
        // edge case
        if(m == 1 && n == 1) return 1;
        
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        // dp[m-1][n-1] = 1;

        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(i == m-1 && j == n-1)
                {
                    dp[i][j] = 1;   // 1 way to reach final destination
                }
                else
                {
                    int down = dp[i+1][j];
                    int right = dp[i][j+1];

                    dp[i][j] = down + right;
                }
            }
        }

        // Time Complexity : O(m*n)
        // Space Complecity : O(m*n) extra space for dp array
        return dp[0][0];
        
    }
};

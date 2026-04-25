class Solution {
public:
    int uniquePaths(int m, int n) {
        // Bottom up tabulation approach
            
        // vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        // dp[m-1][n-1] = 1;

        vector<int>row(n+1, 0);
        vector<int>forwardRow(n+1, 0);
        row[n-1] = 1;

        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(i == m-1 && j == n-1)
                    continue;
                int down = forwardRow[j];
                int right = row[j+1];
                row[j] = down + right;
            }
            swap(forwardRow, row);
        }

        // Time Complexity : O(m*n)
        // Space Complecity : O(n) extra space for dp array
        return forwardRow[0];
        
    }
};

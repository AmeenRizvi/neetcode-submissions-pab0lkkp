class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int maxLen = 0;
        vector<vector<int>>dp(rows+1, vector<int>(cols+1, 0));
        for(int i = rows-1; i >= 0; i--)
        {
            for(int j = cols-1; j >= 0 ; j--)
            {
                if(matrix[i][j] == '1')
                {
                    int right = dp[i][j+1];
                    int down = dp[i+1][j];
                    int diag = dp[i+1][j+1];

                    dp[i][j] = 1 + min({right, down, diag});
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        return maxLen*maxLen;
    }
};
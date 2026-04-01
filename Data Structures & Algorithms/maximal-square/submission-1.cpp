class Solution {
    int solve(int i, int j, vector<vector<char>>& matrix, vector<vector<int>>&dp)
    {
        if(i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] == '0')
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = solve(i, j+1, matrix, dp);
        int down = solve(i+1, j, matrix, dp);
        int diag = solve(i+1, j+1, matrix, dp);

        return dp[i][j] = min({right, down, diag}) + 1;
        
        
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int maxLen = 0;
        vector<vector<int>>dp(rows+1, vector<int>(cols+1, -1));
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(matrix[i][j] == '1')
                {
                    int length = solve(i, j, matrix, dp);
                    maxLen = max(maxLen, length);
                }
            }
        }
        return maxLen*maxLen;
    }
};
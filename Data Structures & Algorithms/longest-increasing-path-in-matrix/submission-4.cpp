class Solution {
    int dfs(int i, int j, vector<vector<int>>& matrix, int val, vector<vector<int>>&dp )
    {
        if(i >= matrix.size() || i < 0 || j >= matrix[0].size() || j < 0 || 
        matrix[i][j] <= val )
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int right = 1 + dfs(i, j+1, matrix, matrix[i][j], dp);
        int left = 1 + dfs(i, j-1, matrix, matrix[i][j], dp);
        int up = 1 + dfs(i+1, j, matrix, matrix[i][j], dp);
        int down = 1 + dfs(i-1, j, matrix, matrix[i][j], dp);

        return dp[i][j] = max({right, left, up, down});
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>>dp(rows, vector<int>(cols, -1));
        int maxLen = INT_MIN;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                int len = dfs(i, j, matrix, INT_MIN, dp);
                maxLen = max(maxLen, len);
            }
        }
        return maxLen; 
    }
};

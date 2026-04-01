class Solution {
    int dfs(int i, int j, vector<vector<int>>& matrix, int val )
    {
        if(i >= matrix.size() || i < 0 || j >= matrix[0].size() || j < 0 || 
        matrix[i][j] <= val )
            return 0;
        
        int p1 = 1 + dfs(i, j+1, matrix, matrix[i][j]);
        int p2 = 1 + dfs(i, j-1, matrix, matrix[i][j]);
        int p3 = 1 + dfs(i+1, j, matrix, matrix[i][j]);
        int p4 = 1 + dfs(i-1, j, matrix, matrix[i][j]);

        return max({p1, p2, p3, p4});
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int maxLen = INT_MIN;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                int len = dfs(i, j, matrix, INT_MIN);
                maxLen = max(maxLen, len);
            }
        }
        return maxLen; 
    }
};

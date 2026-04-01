class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        if(obstacleGrid[rows-1][cols-1] == 1)
            return 0;
        vector<vector<int>>dp(rows+1, vector<int>(cols+1, 0));
        dp[rows-1][cols-1] = 1;

        for(int i = rows-1; i >= 0; i--)
        {
            for(int j = cols-1; j >= 0; j--)
            {
                if(i == rows-1 && j == cols-1)
                    continue;
                if(obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                int p1 = dp[i+1][j];
                int p2 = dp[i][j+1];

                dp[i][j] = p1+p2;
            }
        }
        return dp[0][0];
        
    }
};
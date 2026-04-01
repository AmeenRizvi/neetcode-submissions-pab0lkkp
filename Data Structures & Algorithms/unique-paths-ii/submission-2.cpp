class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[rows-1][cols-1] == 1)
            return 0;
        vector<int>dp(cols+1, 0);
        dp[cols-1] = 1;

        for(int i = rows-1; i >= 0; i--)
        {
            for(int j = cols-1; j >= 0; j--)
            {
                if(i == rows-1 && j == cols-1)
                    continue;
                if(obstacleGrid[i][j] == 1)
                {
                    dp[j] = 0;
                    continue;
                }
                dp[j] += dp[j+1];
            }
        }
        return dp[0];
        
    }
};
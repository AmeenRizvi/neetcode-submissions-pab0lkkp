class Solution {
    int m, n;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1] == 1) return 0;
        // vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        vector<int>row(n+1, 0);
        vector<int>forwardRow(n+1, 0);

        row[n-1] = 1;
        
        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(i == m-1 && j == n-1)
                {
                    continue;
                }
                if(obstacleGrid[i][j] == 1 )
                {
                    row[j] = 0;
                }
                else
                {
                    int down = forwardRow[j];
                    int right = row[j+1];

                    row[j] = down + right;
                }
            }
            swap(row, forwardRow);
        }
        return forwardRow[0];


    }
};
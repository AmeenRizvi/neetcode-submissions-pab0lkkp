class Solution {
    int rows, cols;
    int dfs(int i, int j, vector<vector<int>>& grid)
    {
        if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0)
        {
            return 0;
        }

        grid[i][j] = 0;

        int up = dfs(i-1, j, grid);
        int down = dfs(i+1, j, grid);
        int left = dfs(i, j-1, grid);
        int right = dfs(i, j+1, grid);

        return 1 + up + down + left + right;
    }


public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() )
        {
            return 0;
        }

        rows = grid.size();
        cols = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    int area = dfs(i, j, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

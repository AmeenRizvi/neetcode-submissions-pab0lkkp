class Solution {
    int dfs(int i, int j, vector<vector<int>>& grid)
    {
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] == 0)
        {
            return 1;
        }
        if(grid[i][j] == 2)
            return 0;

        grid[i][j] = 2;
        int left = dfs(i, j-1, grid);
        int right = dfs(i, j+1, grid);
        int up = dfs(i+1, j, grid);
        int down = dfs(i-1, j, grid);

        return left + right + up + down;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 1)
                {
                    return dfs(i, j, grid);
                }
            }
        }
        
    }
};
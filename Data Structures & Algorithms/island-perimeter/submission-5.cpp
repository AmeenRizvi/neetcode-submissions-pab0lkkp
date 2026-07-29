class Solution {
    int rows, cols;
    const int visited = 2;

    int dfs(int i, int j, vector<vector<int>>& grid)
    {
        if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0)
        {
            return 1;
        }
        if(grid[i][j] == visited)
        {
            return 0;
        }

        grid[i][j] = visited;
        int up = dfs(i+1, j, grid);
        int down = dfs(i-1, j, grid);
        int left = dfs(i, j-1, grid);
        int right = dfs(i, j+1, grid);

        return up + down + left + right;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    return dfs(i, j, grid);
                }
            }
        }
        return 0;
    }
};
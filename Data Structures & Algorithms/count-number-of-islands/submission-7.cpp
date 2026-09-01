class Solution {
    int rows, cols;
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1')
        {
            return;
        }

        grid[i][j] = '0';
        dfs(i-1, j, grid);
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
        {
            return 0;
        }

        rows = grid.size();
        cols = grid[0].size();
        int count = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};

class Solution {
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        if(i >= grid.size() || j >= grid[i].size() || i < 0 || j < 0 ||
        grid[i][j] != '1')
            return;
        
        grid[i][j] = '#';
        dfs(i+1, j, grid);
        dfs(i, j+1, grid);
        dfs(i-1, j, grid);
        dfs(i, j-1, grid);

    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
        
    }
};

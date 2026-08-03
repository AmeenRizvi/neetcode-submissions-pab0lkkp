class Solution {
    bool checkRow(int row, int col, vector<vector<int>>& grid)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            if(j != col && grid[row][j] == 1)
            {
                return true;
            }
        }
        return false;
    }
    bool checkCol(int row, int col, vector<vector<int>>& grid)
    {
        for(int i = 0; i < grid.size(); i++)
        {
            if(i != row && grid[i][col] == 1)
            {
                return true;
            }
        }
        return false;
    }
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    bool serverInRow = checkRow(i, j, grid);
                    bool serverInCol = checkCol(i, j, grid);

                    if(serverInRow || serverInCol)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
        
    }
};
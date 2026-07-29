class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    ans += 4;
                    if(i && grid[i-1][j])
                    {
                        ans -= 2;
                    }
                    if(j && grid[i][j-1])
                    {
                        ans -= 2;
                    }
                }
            }
        }
        return ans;
        
    }
};
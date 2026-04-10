class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)  // only 1 island, all land cells connected
                {
                    ans += (i+1 >= rows || grid[i+1][j] == 0) ? 1 : 0;
                    ans += (j+1 >= cols || grid[i][j+1] == 0) ? 1 : 0;
                    ans += (i-1 < 0 || grid[i-1][j] == 0) ? 1 : 0;
                    ans += (j-1 < 0 || grid[i][j-1] == 0) ? 1 : 0;
                }
            }
        }
        return ans;  // if no land, then perimeter = 0
        
    }
};
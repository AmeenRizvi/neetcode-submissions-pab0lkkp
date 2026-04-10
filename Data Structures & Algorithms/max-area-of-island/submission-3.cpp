class Solution {
    int rows, cols;
    const int visited = 2; // to mark as visited land cell
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; // traverse option

    int dfs(int i, int j, vector<vector<int>>& grid)
    {
        if(i >= rows || i < 0 || j >= cols || j < 0 || grid[i][j] != 1)
        {
            return 0;
        }
        
        grid[i][j] = visited;

        int left = dfs(i, j-1, grid);
        int right = dfs(i, j+1, grid);
        int up = dfs(i+1, j, grid);
        int down = dfs(i-1, j, grid);

        return 1 + left + right + up + down;

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // edge case - grid is empty
        if(grid.empty()) return 0;

        rows = grid.size();
        cols = grid[0].size();

        int maxArea = 0;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                // land cell found
                if(grid[i][j] == 1)
                {
                    int area = dfs(i, j, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        // Time complexity - O(rows * cols)
        // Space complexity - O(rows * cols) extra sapce in worst case for stack
        return maxArea;
    }
};

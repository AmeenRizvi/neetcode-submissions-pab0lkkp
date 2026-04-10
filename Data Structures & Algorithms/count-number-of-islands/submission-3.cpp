class Solution {
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        // Base case
        // coordinates beyond matrix or not a visited land cell
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] != '1' )
        {
            return;
        }

        grid[i][j] = '2'; // mark as visited

        // traverse 4 paths - down, up, right , left
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        
        int rows = grid.size(), cols = grid[0].size();
        int countIslands = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    countIslands++;
                    dfs(i, j, grid);
                }
            }
        }
        // Time Complexity : O(rows * cols)
        // Space Complexity : O(rows * cols) extra space in worst case

        return countIslands;
        
    }
};

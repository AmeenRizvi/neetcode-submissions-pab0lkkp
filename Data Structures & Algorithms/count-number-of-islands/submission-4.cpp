class Solution {
    const char VISITED = '2';
    int ROWS, COLS;
    void exploreIslandDFS(int i, int j, vector<vector<char>>& grid)
    {
        // Base case
        //  Out of Bonds or unvisited land cell
        if(i >= ROWS || i < 0 || j >= COLS || j < 0 || grid[i][j] != '1' )
        {
            return;
        }

        grid[i][j] = VISITED; // mark as visited

        // traverse 4 paths - down, up, right , left
        exploreIslandDFS(i+1, j, grid);
        exploreIslandDFS(i-1, j, grid);
        exploreIslandDFS(i, j+1, grid);
        exploreIslandDFS(i, j-1, grid);

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        ROWS = grid.size();
        COLS = grid[0].size();
        int countIslands = 0;

        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(grid[i][j] == '1')
                {
                    countIslands++;
                    exploreIslandDFS(i, j, grid);
                }
            }
        }
        // Time Complexity : O(rows * cols)
        // Space Complexity : O(rows * cols) extra space in worst case in recursion stack

        return countIslands;
        
    }
};

class Solution {
    int dfs(int i , int j, vector<vector<int>>& grid, vector<vector<int>>&vis )
    {
        int n = grid.size(), m = grid[0].size();
        if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == 0)
            return 1;
        if(vis[i][j] == 1)
            return 0;
        
        vis[i][j] = 1;
        int p1 = dfs(i+1, j, grid, vis);
        int p2 = dfs(i, j+1, grid, vis);
        int p3 = dfs(i-1, j, grid, vis);
        int p4 = dfs(i, j-1, grid, vis);

        return p1+p2+p3+p4;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int perimeter = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                {
                    perimeter = max(perimeter, dfs(i, j, grid, vis) );
                }
            }
        }
        return perimeter;
        
    }
};
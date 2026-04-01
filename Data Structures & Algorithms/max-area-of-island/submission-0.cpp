class Solution {
    int dfs(int i ,int j, vector<vector<int>>& grid, vector<vector<bool>>& vis)
    {
        int n = grid.size(), m = grid[0].size();
        if(i >= n || i < 0 || j >= m || j < 0 || vis[i][j] == true || grid[i][j]==0)
        {
            return 0;
        }

        vis[i][j] = true;
        int p1 = dfs(i+1, j, grid, vis);
        int p2 = dfs(i, j+1, grid, vis);
        int p3 = dfs(i-1, j, grid, vis);
        int p4 = dfs(i, j-1, grid, vis);

        return 1+p1+p2+p3+p4;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        
        int area = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == false)
                {
                    area = max(area, dfs(i, j, grid, vis) );
                }
            }
        }
        return area;
    }
};

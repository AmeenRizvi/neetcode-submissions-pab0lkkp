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

    int directions[4][2] = { {1,0}, {-1, 0}, {0, 1}, {0,-1} };
    int bfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis )
    {
        queue<vector<int>>q;
        q.push({i,j});
        vis[i][j] = true;
        int ans = 1;

        while(!q.empty())
        {
            vector<int> front = q.front();
            q.pop();
            

            for(int i = 0; i < 4; i++)
            {
                int ni = front[0] + directions[i][0];
                int nj = front[1] + directions[i][1];

                if(ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size() && grid[ni][nj]==1 && !vis[ni][nj])
                {
                    
                    q.push({ni, nj});
                    vis[ni][nj] = true;
                    ans++;

                }
            }
        }
        return ans;


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
                    area = max(area, bfs(i, j, grid, vis) );
                }
            }
        }
        return area;
    }
};

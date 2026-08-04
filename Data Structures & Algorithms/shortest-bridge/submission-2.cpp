class Solution {
    int rows, cols;
    int directions[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &vis)
    {
        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = true;
        grid[i][j] = 2;

        while(!q.empty() )
        {
            auto [x, y] = q.front();
            q.pop();

            for(auto &dir : directions)
            {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols && 
                !vis[new_x][new_y] && grid[new_x][new_y] == 1 )
                {
                    vis[new_x][new_y] = true;
                    q.push({new_x, new_y});
                    grid[new_x][new_y] = 2;
                }
            }
        }
    }
    // multi source bfs
    int multiBFS(vector<vector<int>>& grid, vector<vector<bool>>&vis)
    {
        queue<pair<int,int>>q;
        vector<vector<bool>>multiVIS(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(vis[i][j])
                {
                    q.push({i, j});
                    multiVIS[i][j] = true;
                }
            }
        }

        int count = 0;
        while(!q.empty() )
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto [x, y] = q.front();
                q.pop();
                

                for(auto &dir : directions)
                {
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];

                    

                    if(new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols
                    && !multiVIS[new_x][new_y])
                    {
                        if(grid[new_x][new_y] == 1)
                        {
                            return count;
                        }
                        q.push({new_x, new_y});
                        multiVIS[new_x][new_y] = true;
                    }
                }
            }
            count++;
        }
        return -1;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        vector<vector<bool>>vis(rows, vector<bool>(cols, false));
        bool found = false;
        for(int i = 0; i < rows && !found; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    bfs(i, j, grid, vis);
                    found = true;
                    break;
                }
            }
        }

        return multiBFS(grid, vis);
        
        
        
    }
};
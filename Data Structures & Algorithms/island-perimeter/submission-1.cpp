class Solution {
    int directions[4][2] = { {1, 0}, {-1,0}, {0,1}, {0,-1} };
    int bfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>&vis)
    {
        queue<pair<int,int>>q;
        q.push({i, j});
        vis[i][j] = true;
        int ans = 0;

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int newX = x + directions[i][0];
                int newY = y + directions[i][1];

                if(newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[0].size() 
                || grid[newX][newY] == 0)
                {
                    ans += 1;
                }
                else if(vis[newX][newY])
                {
                    ans += 0;
                }
                else
                {
                    q.push({newX, newY});
                    vis[newX][newY] = true;
                }
            }
        }
        return ans;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>>vis(rows, vector<bool>(cols));
        int ans = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                {
                    ans = bfs(i, j, grid, vis);
                }
            }
        }
        return ans;
    }
};
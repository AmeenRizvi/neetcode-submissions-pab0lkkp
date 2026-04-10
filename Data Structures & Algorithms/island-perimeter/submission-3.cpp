class Solution {
    vector<vector<int>>directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int bfs(int i, int j, vector<vector<int>>& grid)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j] = 2;

        int ans = 0;

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(auto &dir : directions)
            {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if(newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[0].size()
                || grid[newX][newY] == 0)
                {
                    ans += 1;
                }
                else if(grid[newX][newY] == 2)
                {
                    continue;
                }
                else
                {
                    q.push({newX, newY});
                    grid[newX][newY] = 2;
                }
            }
        }
        return ans;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 1)
                {
                    return bfs(i, j, grid);
                }
            }
        }
        return -1;
        
    }
};
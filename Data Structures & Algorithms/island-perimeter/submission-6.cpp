class Solution {
    int rows, cols;
    const int visited = 2;
    int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}  };

    int bfs(int i, int j, vector<vector<int>>& grid)
    {
        queue<pair<int,int>> q;
        q.push({i, j});
        grid[i][j] = visited;
        int ans = 0;

        while(!q.empty() )
        {
            auto [x, y] = q.front();
            q.pop();

            for(auto &dir : directions)
            {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(new_x < 0 || new_x >= rows || new_y < 0 || new_y >= cols || grid[new_x][new_y] == 0)
                {
                    ans += 1;
                }
                else if(grid[new_x][new_y] == 1)
                {
                    q.push({new_x, new_y});
                    grid[new_x][new_y] = visited;
                }
            }
        }
        return ans;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    return bfs(i, j, grid);
                }
            }
        }
        return 0;
    }
};
class Solution {
    int rows, cols;
    int directions[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

    int bfs(int i, int j, vector<vector<int>>& grid)
    {
        queue<pair<int,int> >q;
        int count = 0;

        q.push({i, j});
        grid[i][j] = 0;

        while(!q.empty() )
        {
            auto [x, y] = q.front();
            q.pop();
            count++;

            for(auto &dir : directions)
            {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols && 
                grid[new_x][new_y] == 1)
                {
                    grid[new_x][new_y] = 0;
                    q.push({new_x, new_y});
                }
            }
        }
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    int area = bfs(i, j, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

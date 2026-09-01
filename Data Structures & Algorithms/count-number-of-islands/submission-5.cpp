class Solution {
    int rows, cols;
    int directions[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

    void bfs(int i, int j, vector<vector<char>>& grid)
    {
        queue<pair<int,int> >q;
        q.push({i, j});
        grid[i][j] = '0';

        while(!q.empty() )
        {
            auto [x, y] = q.front();
            q.pop();

            for(auto &dir : directions)
            {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols
                && grid[new_x][new_y] == '1')
                {
                    grid[new_x][new_y] = '0';
                    q.push({new_x, new_y});
                }
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
        {
            return 0;
        }

        rows = grid.size();
        cols = grid[0].size();
        int count = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    count++;
                    bfs(i, j, grid);
                }
            }
        }
        return count;
    }
};

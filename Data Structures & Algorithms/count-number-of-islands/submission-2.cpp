class Solution {
    void bfs(int i, int j, vector<vector<char>>& grid)
    {
        queue<pair<int,int>> q;
        q.push({i, j});
        grid[i][j] = '2';

        int directions[4][2] = {{-1,0}, {1, 0}, {0, 1}, {0, -1} };

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(auto &dir : directions)
            {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size()
                && grid[newX][newY] == '1')
                {
                    q.push({newX, newY});
                    grid[newX][newY] = '2';
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int countIslands = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    countIslands++;
                    bfs(i, j, grid);
                }
            }
        }
        return countIslands;
        
    }
};

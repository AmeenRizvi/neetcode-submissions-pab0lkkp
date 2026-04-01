class Solution {
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        if(i >= grid.size() || j >= grid[i].size() || i < 0 || j < 0 ||
        grid[i][j] != '1')
            return;
        
        grid[i][j] = '#';
        dfs(i+1, j, grid);
        dfs(i, j+1, grid);
        dfs(i-1, j, grid);
        dfs(i, j-1, grid);

    }

    vector<vector<int>>directions = {{0,1}, {1, 0}, {0,-1}, {-1, 0}};

    void bfs(int i, int j, vector<vector<char>>& grid)
    {
        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];

                if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()
                && grid[nx][ny] == '1')
                {
                    q.push({nx, ny});
                    grid[nx][ny] = '#';
                }
            }


        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    bfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
        
    }
};

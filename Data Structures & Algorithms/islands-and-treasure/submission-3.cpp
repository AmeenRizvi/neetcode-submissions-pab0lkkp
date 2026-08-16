class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int> >q;
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }
        
        int directions[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
        int dist = 1;
        while(!q.empty() )
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++ )
            {
                auto [x, y] = q.front();
                q.pop();

                for(auto &dir : directions)
                {
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];

                    if(new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols
                    && grid[new_x][new_y] == INT_MAX)
                    {
                        grid[new_x][new_y] = dist;
                        q.push({new_x, new_y});
                    }
                }
            }
            dist++;
        }
        
    }
};

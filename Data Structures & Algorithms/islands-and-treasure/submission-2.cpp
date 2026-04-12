class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // Edge case
        if(grid.empty()) return;

        int m = grid.size(), n = grid[0].size();

        // Multi Source BFS
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // Push all treasure chest into queue
                if(grid[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }
        
        int directions[4][2] = { {-1, 0} , {1, 0}, {0, -1}, {0, 1} }; // traverse horizontally and vertically
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(auto &dir : directions)
            {
                // New coordinates
                int newX = x + dir[0];
                int newY = y + dir[1];

                // within matrix and unvisited land cell 
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == INT_MAX)
                {
                    q.push({newX, newY});
                    grid[newX][newY] = grid[x][y] + 1;
                }
            }
        }
        
    }
};

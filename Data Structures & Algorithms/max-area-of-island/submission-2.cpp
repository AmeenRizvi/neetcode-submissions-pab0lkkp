class Solution {
    int rows, cols;
    const int visited = 2; // to mark as visited land cell
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; // traverse option

    int bfs(int i, int j, vector<vector<int>>& grid)
    {
        queue<pair<int,int>> q;
        q.push({i, j});
        grid[i][j] = visited;
        int area = 1;

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(auto &dir : directions)
            {
                int newX = x + dir[0];
                int newY = y + dir[1];

                // within matrix and an unvisited land cell
                if(newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1)
                {
                    q.push({newX, newY});
                    grid[newX][newY] = visited;
                    area++;
                }
            }
        }
        return area;

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // edge case - grid is empty
        if(grid.empty()) return 0;

        rows = grid.size();
        cols = grid[0].size();

        int maxArea = 0;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                // land cell found
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

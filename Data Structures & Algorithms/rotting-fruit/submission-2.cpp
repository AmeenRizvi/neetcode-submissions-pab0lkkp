class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // edge case
        if(grid.empty()) return 0;

        int rows = grid.size(), cols = grid[0].size();
        int countFresh = 0;

        queue<pair<int,int>> q;
        // Push all rotten fruits into queue
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1)
                {
                    countFresh++;
                }
            }
        }
        
        int changeFresh = 0;
        int minutes = 0;
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; // traverse horizontally or vertically
        while(!q.empty())
        {
            int sz = q.size();
            int changes = 0;
            for(int i = 0; i < sz; i++)
            {
                auto [x, y] = q.front();
                q.pop();

                for(auto &dir : directions)
                {
                    // new cooridnates
                    int newX = x + dir[0];
                    int newY = y + dir[1];
                
                
                    // new coordinates should be within the matrix and a fresh fruit
                    if(newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1)
                    {
                        q.push({newX, newY});
                        grid[newX][newY] = 2; // marks as visited and rotten
                        changes++;
                    }
                }
            }
            changeFresh += changes;
            minutes += changes > 0 ? 1 : 0;
        }
        // Time Complexity : O(rows * cols)
        // Space complexity : O(rows * cols) extra space in worst case due to queue

        return countFresh == changeFresh ? minutes : -1; // answer
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int,int> >q;
        int freshFruits = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                if(grid[i][j] == 1)
                {
                    freshFruits++;
                }
            }
        }

        int directions[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
        int minutes = 0;
        while(!q.empty() )
        {
            int sz = q.size();
            bool turnedRotten = false;

            for(int i = 0; i < sz; i++)
            {
                auto [x, y] = q.front();
                q.pop();

                for(auto &dir : directions)
                {
                    int newX = x + dir[0];
                    int newY = y + dir[1];

                    if(newX >= 0 && newX < rows && newY >= 0 && newY < cols 
                    && grid[newX][newY] == 1)
                    {
                        freshFruits--;
                        q.push({newX, newY});
                        grid[newX][newY] = 2;
                        turnedRotten = true;
                    }
                }
            }
            if(turnedRotten)
            {
                minutes++;
            }
        }

        return freshFruits == 0 ? minutes : -1;
        
    }
};

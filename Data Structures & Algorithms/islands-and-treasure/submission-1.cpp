class Solution {
    int directions[4][2] = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>>q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0)
                {
                    q.push({i,j});
                }
            }
        }
    
        while(!q.empty())
        {
            
            
                auto [r,c] = q.front();
                q.pop();

                for(auto &dir : directions)
                {
                    int newR = r + dir[0], newC = c + dir[1];
                    if(newR < 0 || newC < 0 || newR >= n || newC >= m || grid[newR][newC] != INT_MAX)
                    {
                        continue;                                                                                                      
                    }
                    grid[newR][newC] = grid[r][c] + 1;
                    q.push({newR, newC});
                }
            
            
        }
    }
};

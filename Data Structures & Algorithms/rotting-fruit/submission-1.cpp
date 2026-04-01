class Solution {
    int directions[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>>q;
        int n = grid.size(), m = grid[0].size();
        int fresh = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    fresh++;
                }
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
            }
        }

        int time = 0;
        while(fresh > 0 && !q.empty())
        {
            int sz = q.size();
            for(int k = 0; k < sz; k++)
            {
                vector<int>front = q.front();
                int i = front[0];
                int j = front[1];
                q.pop();

                for(auto &[x, y] : directions)
                {
                    int ni = i+x;
                    int nj = j+y;
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m)
                    {
                        if(grid[ni][nj] == 1)
                        {
                            grid[ni][nj] = 2;
                            q.push( {ni,nj} );
                            fresh--;
                        }
                    }
                }
            }
            time++;
        }


        return fresh == 0 ? time : -1;


        
    }
};

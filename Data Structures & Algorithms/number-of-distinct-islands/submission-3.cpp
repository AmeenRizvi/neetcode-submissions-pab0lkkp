class Solution {
    int rows, cols;
    int directions[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    char dirChars[4] = {'U', 'D', 'R', 'L'};
    const int visited = 2;

    void dfs(int i, int j,vector<vector<int>>& grid, string &vis)
    {
        for(int k = 0; k < 4; k++)
        {
            int new_i = i + directions[k][0];
            int new_j = j + directions[k][1];

            if(new_i >= 0 && new_i < rows && new_j >= 0 && new_j < cols && 
            grid[new_i][new_j] == 1)
            {
                vis += dirChars[k];
                grid[new_i][new_j] = visited;
                dfs(new_i, new_j, grid, vis);
                vis += 'B';            
            }
        }
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        unordered_set<string>s;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    string vis = "#";
                    dfs(i, j, grid, vis);
                    s.insert(vis);
                    grid[i][j] = visited;
                }
            }
        }
        return s.size();
    }
};

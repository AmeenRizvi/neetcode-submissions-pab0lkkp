class Solution {
    bool dfs(int m, int n, vector<vector<int>>& maze, vector<int> curr, vector<int>& destination,
    vector<vector<bool>> &visit )
    {
        if(visit[curr[0]][curr[1]])
            return false;
        if(curr[0] == destination[0] && curr[1] == destination[1])
            return true;

        visit[curr[0]][curr[1]] = true;

        int directions[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

        for(int i = 0; i < 4; i++)
        {
            int r = curr[0], c = curr[1];

            while(r >= 0 && r < m && c >= 0 && c < n && maze[r][c] == 0)
            {
                r += directions[i][0];
                c += directions[i][1];
            }

            if(dfs(m, n, maze, {r-directions[i][0], c-directions[i][1]}, destination, visit) )
            {
                return true;
            }
        }
        return false;

    }
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();

        vector<vector<bool>> visit(m, vector<bool>(n));
        return dfs(m, n, maze,start, destination, visit );
    }
};

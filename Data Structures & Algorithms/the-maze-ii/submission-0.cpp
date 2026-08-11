class Solution {
    int rows, cols;
    int directions[4][2] = {  {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
    const int visited = 2;

    bool isValidStart(vector<vector<int>>& maze, vector<int>& start)
    {
        return maze[start[0]][start[1]] == 0;
    }
    bool isValidDestination(vector<vector<int>>& maze, vector<int>& destination)
    {
        int noWalls = 0;
        for(auto &dir : directions)
        {
            int new_i = destination[0] + dir[0];
            int new_j = destination[1] + dir[1];

            if(new_i >= 0 && new_i < rows && new_j >= 0 && new_j < cols 
            && maze[new_i][new_j] == 0)
            {
                noWalls++;
            }
        }
        return noWalls == 1;

    }

    int dfs(vector<vector<int>>& maze, vector<int> curr, vector<int>& destination)
    {
        if(curr[0] < 0 || curr[0] >= rows || curr[1] < 0 || curr[1] >= cols
        || maze[curr[0]][curr[1]] != 0)
        {
            return 0;
        }

        if(curr == destination)
        {
            return 1;
        }

        maze[curr[0]][curr[1]] = visited;
        int up = dfs(maze, {curr[0] - 1, curr[1] + 0 }, destination);
        int down = dfs(maze, {curr[0] + 1, curr[1] + 0 }, destination);
        int left = dfs(maze, {curr[0] , curr[1] - 1 }, destination);
        int right = dfs(maze, {curr[0] , curr[1] + 1 }, destination);

        maze[curr[0]][curr[1]] = 0;

        return min({up, down, left, right}) + 1;


    }
    void dijikstra(vector<vector<int>>& maze, vector<int>& start, vector<vector<int>>&distance)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, start[0], start[1]});

        while(!pq.empty() )
        {
            vector<int>s = pq.top();
            pq.pop();

            int dist = s[0], sx = s[1], sy = s[2];

            if(distance[sx][sy] < dist)
            {
                continue;
            }

            for(auto &dir : directions)
            {
                int x = sx + dir[0];
                int y = sy + dir[1];
                int count = 0;

                while(x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0)
                {
                    x += dir[0];
                    y += dir[1];
                    count++;
                }

                if(distance[sx][sy] + count < distance[x - dir[0] ][y - dir[1] ])
                {
                    distance[x - dir[0] ][y - dir[1] ] = distance[sx][sy] + count;
                    pq.push({distance[x - dir[0] ][y - dir[1] ], x-dir[0], y-dir[1]});
                }
            }
        }
    }
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        rows = maze.size();
        cols = maze[0].size();

        // if(!isValidStart(maze, start) || !isValidDestination(maze, destination) )
        // {
        //     return -1;
        // }

        vector<vector<int>>distance(rows, vector<int>(cols, INT_MAX));
        distance[start[0]][start[1]] = 0;

        dijikstra(maze, start, distance);

        return distance[destination[0]][destination[1]] == INT_MAX ? -1 : 
        distance[destination[0]][destination[1]];





        // return dfs(maze, start, destination);
        
    }
};

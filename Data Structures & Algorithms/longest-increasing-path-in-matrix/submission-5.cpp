class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> indegree(rows, vector<int>(cols, 0));
        int directions[4][2] = { {-1,0}, {1, 0}, {0, 1}, {0, -1}  };

        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                for(auto &d : directions)
                {
                    int nr = r + d[0], nc = c + d[1];
                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] < matrix[r][c])
                    {
                        indegree[r][c]++;
                    }
                }
            }
        }

            queue<pair<int,int>>q;
            for(int r = 0; r < rows; r++)
            {
                for(int c = 0; c < cols; c++)
                {
                    if(indegree[r][c] == 0)
                    {
                        q.push({r,c});
                    }
                }
            }

            int ans = 0;
            while(!q.empty())
            {
                int sz = q.size();
                for(int i = 0; i < sz; i++)
                {
                    auto [r,c] = q.front();
                    q.pop();
                    for(auto &d : directions)
                    {
                        int nr = r + d[0], nc = c + d[1];
                        if(nr >= 0 && nr < rows && nc >= 0 && nc < cols 
                        && matrix[nr][nc] > matrix[r][c])
                        {
                            indegree[nr][nc]--;
                            if(indegree[nr][nc] == 0)
                            {
                                q.push({nr, nc});
                            }
                        }
                    }
                }
                ans++;
        }
        return ans;

        
    }
};

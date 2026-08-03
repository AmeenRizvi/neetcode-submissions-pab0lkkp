class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int>countRows(m, 0);
        vector<int>countCols(n, 0);

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    countRows[i]++;
                    countCols[j]++;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1 && max(countRows[i], countCols[j] ) > 1)
                {
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
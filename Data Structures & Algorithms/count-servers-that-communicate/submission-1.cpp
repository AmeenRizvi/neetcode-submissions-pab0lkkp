class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int>row_cnt(rows, 0), col_cnt(cols, 0);

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    row_cnt[i]++;
                    col_cnt[j]++;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1 && max(row_cnt[i], col_cnt[j])>1 )
                {
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
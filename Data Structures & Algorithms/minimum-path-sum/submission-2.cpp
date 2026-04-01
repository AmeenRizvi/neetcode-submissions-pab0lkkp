class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        vector<int>curRow(n+1, 0);
        vector<int>forRow(n+1, INT_MAX);
        
        curRow[n] = INT_MAX;
        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(i == m-1 && j == n-1)
                {
                    curRow[n-1] = grid[i][j];
                    continue;
                }
                
                int p1 = forRow[j];
                int p2 = curRow[j+1];

                curRow[j] = min(p1, p2) + grid[i][j];
            }
            swap(curRow, forRow);
        }
        return forRow[0];
        
    }
};
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Bottom Up Tabulation approach
        int m = grid.size(), n = grid[0].size();
        vector<int>currRow(n+1, 0);
        currRow[n] = INT_MAX;
        vector<int>forwardRow(n+1, INT_MAX);
        // Outside grid not allowed so will take very large number
        
        currRow[n-1] = grid[m-1][n-1];
        
        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(i == m-1 && j == n-1)
                {
                    continue;
                }
                int down = forwardRow[j];
                int right = currRow[j+1];

                currRow[j] = min(down, right) + grid[i][j];
            }
            swap(currRow, forwardRow);
        }
        // Time Complexity : O(m*n)
        // Space Complexity : O(m*n)
        return forwardRow[0];
        
    }
};
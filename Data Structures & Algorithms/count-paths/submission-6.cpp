class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        vector<int>row(n+1, 0);
        vector<int>nextRow(n+1, 0);
        row[n-1] = 1;

        for(int i = m-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(i == m-1 && j == n-1)
                    continue;

                int p1 = nextRow[j];
                int p2 = row[j+1];

                row[j] = p1 + p2;
            }
            swap(row, nextRow);
        }
        return nextRow[0];
    }
};

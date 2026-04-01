class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size(), cols = triangle[rows-1].size();
        vector<vector<int>>dp(rows+1, vector<int>(cols+1, 0));

        for(int i = cols-1; i >= 0; i--)
        {
            dp[rows-1][i] = triangle[rows-1][i];
        }

        for(int j = rows-2; j >= 0; j--)
        {
            for(int i = cols-1; i >= 0; i--)
            {
                dp[j][i] = min(dp[j+1][i], dp[j+1][i+1]) + triangle[j][i];
            }
        }
        return dp[0][0];
        
    }
};
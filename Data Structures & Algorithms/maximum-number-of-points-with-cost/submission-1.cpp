class Solution {
    long long solve(int i, int j, vector<vector<int>>& points, vector<vector<long long>>&dp)
    {
        if(i >= points.size()-1)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        long long ans = 0;
        for(int k = 0; k < points[i].size(); k++)
        {
            long long tmp = (long long)points[i+1][k] + solve(i+1, k, points, dp) - abs(j-k);
            ans = max(ans, tmp);
        }
        return dp[i][j] = ans ;
    }
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size(), cols = points[0].size();
        vector<vector<long long>>dp(rows+1, vector<long long>(cols+1, -1));
        long long ans = 0;
        for(int c = 0; c < cols; c++)
        {
            ans = max(ans,(long long)points[0][c] + solve(0, c, points, dp) );
        }
        return ans;
        
    }
};
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
        vector<long long>dp(points[0].begin(), points[0].end());
        long long ans = 0;
        
        for(int r = 1; r < rows; r++)
        {
            vector<long long>left(cols), right(cols);
            left[0] = dp[0];

            for(int c = 1; c < cols; c++)
            {
                left[c] = max(dp[c], left[c-1]-1);
            }

            right[cols-1] = dp[cols-1];
            for(int c = cols-2; c >= 0; c--)
            {
                right[c] = max(dp[c], right[c+1]-1);
            }

            vector<long long>nextDp(cols);
            for(int c = 0; c < cols; c++)
            {
                nextDp[c] = points[r][c] + max(left[c], right[c]);
            }

            dp= move(nextDp);
        }

        return *max_element(dp.begin(), dp.end());
        
    }
};
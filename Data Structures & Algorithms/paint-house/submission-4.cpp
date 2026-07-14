class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>>dp(n+1, vector<int>(4, 0));

        for(int idx = n-1; idx >= 0; idx--)
        {
    
            dp[idx][0] = costs[idx][0] + min(dp[idx+1][1], dp[idx+1][2]);
            dp[idx][1] = costs[idx][1] + min(dp[idx+1][0], dp[idx+1][2]);
            dp[idx][2] = costs[idx][2] + min(dp[idx+1][0], dp[idx+1][1]);
        }

        int ans = dp[0][2];
        for(int i = 2; i >= 0; i--)
        {
            ans = min(ans, dp[0][i]);
        }
        return ans;
        
    }
};
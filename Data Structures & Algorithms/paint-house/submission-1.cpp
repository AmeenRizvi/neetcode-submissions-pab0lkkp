class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>>dp(n+1, vector<int>(3, 0));
        
        for(int iC = 0; iC < 3; iC++)
        {
            dp[n-1][iC] = costs[n-1][iC];
        }
        for(int iH = n-2; iH >= 0; iH--)
        {
            for(int iC = 0; iC < 3; iC++)
            {
                dp[iH][iC] = min(dp[iH+1][ (iC+1)%3 ], dp[iH+1][ (iC+2)%3 ] ) + costs[iH][iC];
            }
        }

        return min({ dp[0][0], dp[0][1], dp[0][2] });
        
    }
};
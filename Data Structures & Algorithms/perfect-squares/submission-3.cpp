class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1, 1e9);
        dp[0] = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int num = 1; num*num <= i; num++)
            {
                dp[i] = min(dp[i], 1 + dp[i - num*num]);
            }
        }
        return dp[n];
    }
};
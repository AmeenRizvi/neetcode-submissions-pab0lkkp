class Solution {
public:
    int numWays(int n, int k) {
        vector<int>dp(n+1, 0);
        if(n == 1) return k;

        dp[1] = k;
        dp[2] = k*k;

        for(int i = 3; i <= n; i++)
        {
            int diff = dp[i-1];
            int same = dp[i-2];

            dp[i] = (k-1)*(same  + diff);
        }
        return dp[n];
        
    }
};

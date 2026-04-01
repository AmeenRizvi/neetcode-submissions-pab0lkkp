class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1, 0);
        dp[n] = 1;

        for(int i = n-1; i >= 0; i--)
        {
            int p1 = 0, p2 = 0;
            p1 = dp[i+1];
            if(i+2 <= n)
                p2 = dp[i+2];
            dp[i] = p1 + p2;
        }

        return dp[0];

        
    }
};

class Solution {
public:
    int tribonacci(int n) {
        vector<int>dp(n+1, 0);
        
        // t0 = 1
        dp[1] = 1;      // t1 = 1
        dp[2] = 1;      // t2 = 1
        for(int i = 3; i <= n; i++)
        {
            // tn = tn-3 + tn-2 + tn-1
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }
        return dp[n];  // tn
        
    }
};
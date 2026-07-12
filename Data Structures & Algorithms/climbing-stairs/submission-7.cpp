class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1; // dp[1]
        int prev2 = 1; // dp[0]

        for(int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;  // dp[i] = dp[i-1] + dp[i-2]

            // to iterate forward
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
        
    }
};

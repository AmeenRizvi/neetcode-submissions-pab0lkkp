class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        
        int prev3 = 0;   // t0
        int prev2 = 1;   // t1
        int prev1 = 1;   // t2   

        for(int i = 3; i <= n; i++)
        {
            // tn = tn-3 + tn-2 + tn-1
            // dp[i] = dp[i-3] + dp[i-2] + dp[i-1]
            int curr = prev3 + prev2 + prev1;

            // To iterate forward
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        // Time Complexity : O(n)
        // Space complexity : O(1) extra space for variables 
        return prev1;  // tn
        
    }
};
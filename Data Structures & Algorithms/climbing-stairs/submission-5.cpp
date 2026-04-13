class Solution {
public:
    int climbStairs(int n) {
        // Space optimized tabulation approach
        // starting with n == 0 -> 1, n == 1 -> 1
        int prev2 = 1, prev1 = 1;

        for(int i = 2; i <= n; i++)
        {
            // curr term
            int curr = prev2 + prev1;
            
            // space optimization
            prev2 = prev1;
            prev1 = curr;
        }
        // final answer will be store in prev1

        // Time Complexity : O(n)
        // Space complexity : O(1) extra space
        return prev1;
        
    }
};

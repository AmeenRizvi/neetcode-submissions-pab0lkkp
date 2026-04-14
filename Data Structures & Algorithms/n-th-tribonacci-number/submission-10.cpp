class Solution {
public:
    int tribonacci(int n) {
        // Space optimised Tabulation approach
        // edge case
        if(n <= 1) return n;

        // Tn-3 , Tn-2, Tn-1  
        int prev3 = 0, prev2 = 1, prev1 = 1;

        for(int i = 3; i <= n; i++)
        {
            // Fibonacci pattern
            int curr = prev1 + prev2 + prev3;

            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        // Time complexity : O(n)
        // Space complexity : O(1) extra space
        return prev1;
        
    }
};
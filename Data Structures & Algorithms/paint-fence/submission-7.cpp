class Solution {
public:
    int numWays(int n, int k) {
        if(n == 1) return k;
        if(n == 2) return k*k;

        // vector<int>dp(n+1, 0);
        // dp[i-2]
        int twoFenceBefore = k;
        // dp[i-1]
        int oneFenceBefore = k*k;

        for(int i = 3; i <= n; i++)
        {
            // dp[i] = (k-1)*(same  + diff);
            int curr = (k-1)*(twoFenceBefore + oneFenceBefore);

            // to iterate forward
            twoFenceBefore = oneFenceBefore;
            oneFenceBefore = curr;
        }
        return oneFenceBefore;
        
    }
};

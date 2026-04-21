class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+2, 0);

        // dp[i+2]    ,       dp[i+1]
        int twoStepAhead = 0, oneStepAhead = 0;

        for(int i = n-1; i >= 0; i--)
        {
            // dp[i]
            int currStepAhead = cost[i] + min(twoStepAhead, oneStepAhead);

            // to iterate forward
            twoStepAhead = oneStepAhead;
            oneStepAhead = currStepAhead;
        }

        return min(twoStepAhead, oneStepAhead);
        
    }
};

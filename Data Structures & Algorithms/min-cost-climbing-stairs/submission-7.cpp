class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n, 0);

        for(int i = n-1; i >= 0; i--)
        {
            int twoStepAfter = i+2 < n ? dp[i+2] : 0;
            int oneStepAfter = i+1 < n ? dp[i+1] : 0;

            int currStepCost = cost[i] + min(oneStepAfter, twoStepAfter);
            dp[i] = currStepCost;
        }
        
        return min(dp[0], dp[1]);
    }
};

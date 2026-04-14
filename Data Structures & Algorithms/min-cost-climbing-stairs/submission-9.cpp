class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Tabulation space optimized approach
        int n = cost.size();
        int twoStepAfter = 0, oneStepAfter = 0;

        for(int i = n-1; i >= 0; i--)
        {
            int currStepCost = cost[i] + min(oneStepAfter, twoStepAfter);
            
            twoStepAfter = oneStepAfter;
            oneStepAfter = currStepCost;
        }

        return min(oneStepAfter, twoStepAfter);

        // Time complexity : O(n)
        // Space complexity : O(1) extra space 
    }
};

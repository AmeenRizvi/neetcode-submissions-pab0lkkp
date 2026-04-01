class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 1) return cost[0];

        int prev2 = cost[0], prev1 = cost[1];
        for(int i = 2; i <= n; i++)
        {
            int curr = min(prev1, prev2) + cost[i];
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
        
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int>dp(n+2, 0);
        int next2 = 0;
        int next1 = 0;
        
        for(int i = n-1; i >= 0; i--)
        {
            int curr = min(next1, next2 ) + cost[i];

            next2 = next1;
            next1 = curr;
        }

        return min(next1, next2);
        
    }
};

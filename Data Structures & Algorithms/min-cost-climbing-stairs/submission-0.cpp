class Solution {
    int solve(int n, vector<int>& cost)
    {
        if(n < 0)
        {
            return 0;
        }
        int p1 = solve(n-1, cost);
        int p2 = solve(n-2, cost);
        return cost[n] +  min(p1, p2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(n, cost);
        
    }
};

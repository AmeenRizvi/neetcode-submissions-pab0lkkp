class Solution {
    int n;
    vector<int>dp;

    int solve(vector<int>& cost, int i)
    {
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];

        int currStepCost = cost[i] + min( solve(cost,i+1), solve(cost, i+2) );
        dp[i] = currStepCost;
        return dp[i];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();

        dp.resize(n+1, -1);
        int path1 = solve(cost, 0);
        int path2 = solve(cost, 1);
        
        return min(path1, path2);
    }
};

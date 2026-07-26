class Solution {
    int solve(int i, vector<int>&stones, int totalSum, int sum, vector<vector<int>>&dp)
    {
        if(i >= stones.size() ) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];

        int take = 0;
        if(stones[i] + sum <= totalSum/2)
        {
            take = stones[i] + solve(i+1, stones, totalSum, sum + stones[i], dp );
        }
        int dontTake = solve(i+1, stones, totalSum, sum, dp);

        return dp[i][sum] = max(take, dontTake);
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = 0;
        for(int stone : stones)
        {
            totalSum += stone;
        }
        vector<vector<int>>dp(n+1, vector<int>(totalSum/2+1, -1));

        int s1 = solve(0, stones, totalSum, 0, dp);
        int s2 = totalSum - s1;
        return abs(s1-s2);
    }
};
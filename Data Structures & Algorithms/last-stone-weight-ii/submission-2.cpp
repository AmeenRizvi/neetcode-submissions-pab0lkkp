class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = 0;
        for(int stone : stones)
        {
            totalSum += stone;
        }
        vector<vector<int>>dp(n+1, vector<int>(totalSum/2+1, 0));

        for(int i = n-1; i >= 0; i--)
        {
            for(int sum = totalSum/2; sum >= 0; sum--)
            {
                int take = 0;
                if(sum + stones[i] <= totalSum/2)
                {
                    take = stones[i] + dp[i+1][sum + stones[i]];
                }
                int dontTake = dp[i+1][sum];
                dp[i][sum] = max(take, dontTake);
            }
        }

        int temp = dp[0][0];
        return totalSum - 2*temp;
    }
};
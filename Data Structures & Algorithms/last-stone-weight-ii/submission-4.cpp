class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = 0;
        for(int stone : stones)
        {
            totalSum += stone;
        }
        // vector<vector<int>>dp(n+1, vector<int>(totalSum/2+1, 0));

        // vector<int>row(totalSum/2+1, 0);
        // vector<int>nextRow(totalSum/2+1, 0);

        vector<int>dp(totalSum/2+1, 0);

        for(int i = 0; i < n; i++)
        {
            for(int sum = totalSum/2; sum >= stones[i]; sum--)
            {    
                dp[sum] = max(dp[sum],  stones[i] + dp[sum - stones[i]] );   
            }
        }

        int temp = dp[totalSum/2];
        return totalSum - 2*temp;
    }
};
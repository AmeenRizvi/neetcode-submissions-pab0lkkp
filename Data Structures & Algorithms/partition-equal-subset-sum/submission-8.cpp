class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for(int num : nums)
        {
            totalSum += num;
        }

        if(totalSum % 2 == 1)
        {
            return false;
        }
        int sum = totalSum / 2;

        vector<vector<int>>dp(n+1, vector<int>(2*totalSum+1, 0));

        dp[n][sum] = 1;

        for(int i = n-1; i >= 0; i--)
        {
            for(int s = sum; s >= 0; s--)
            {
                int take = dp[i+1][s + nums[i]];
                int dontTake = dp[i+1][s];

                dp[i][s] = take || dontTake;
            }
        }
        return dp[0][0];
        
    }
};

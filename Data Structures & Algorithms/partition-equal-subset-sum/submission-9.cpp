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

        vector<vector<bool>>dp(n+1, vector<bool>(totalSum+1, false));
        dp[n][sum] = true;

        for(int i = n-1; i >= 0; i--)
        {
            for(int s = sum; s >= 0; s--)
            {
                bool take;
                if(s + nums[i] <= totalSum)
                {
                    take = dp[i+1][s + nums[i]];
                }
                bool dontTake = dp[i+1][s];

                dp[i][s] = take || dontTake;
            }
        }
        return dp[0][0];
        
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for(int prev_i = -1; prev_i < n; prev_i++)
        {
            dp[n][prev_i+1] = 0;
        }

        for(int i = n-1; i >= 0; i--)
        {
            for(int prev_i = i-1; prev_i >= -1; prev_i--)
            {
                int take = 0;
                if(prev_i == -1 || nums[i] > nums[prev_i])
                {
                    take = 1 + dp[i+1][i+1];
                }
                int dontTake = dp[i+1][prev_i+1];

                dp[i][prev_i+1] = max(take, dontTake);
            }
        }
        return dp[0][0];
        
    }
};

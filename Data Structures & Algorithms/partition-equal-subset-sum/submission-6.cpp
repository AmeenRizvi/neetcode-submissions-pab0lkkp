class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total % 2 == 1) return false;
        int target = total / 2;

        vector<vector<bool>>dp(n+1, vector<bool>(target+1, false));
        for(int i = 0; i <= n; i++)
        {
            dp[i][target] = true;
        }
    
        for(int i = n-1; i >= 0; i--)
        {
            for(int sum = target; sum >= 0; sum--)
            {
                if(sum + nums[i] <= target)
                {
                    dp[i][sum] = dp[i + 1][sum + nums[i]] || dp[i+1][sum];
                }
                else
                {
                    dp[i][sum] = dp[i+1][sum];
                }
            }
        }
        return dp[0][0];        
    }
};

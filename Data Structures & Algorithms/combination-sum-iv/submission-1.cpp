class Solution {
    int solve(int target, vector<int>&nums, vector<int>&dp)
    {
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(dp[target] != -1) return dp[target];

        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = solve(target - nums[i], nums, dp);
            ans += temp;
        }
        return dp[target] = ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(target+1, 0);
        // return solve(target, nums, dp);
        dp[0] = 1;
        for(int i = 1; i <= target; i++)
        {
            int ans = 0;
            for(int j = 0; j < n; j++)
            {
                int temp = i - nums[j] >= 0 ? dp[i - nums[j]] : 0;
                ans += temp;
            }
            dp[i] = ans;
        }
        return dp[target];
        
    }
};
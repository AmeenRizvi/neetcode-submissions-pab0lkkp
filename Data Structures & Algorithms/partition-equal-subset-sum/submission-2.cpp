class Solution {
    bool solve(int idx, vector<int>& nums, int sum, vector<vector<int>>&dp )
    {
        if(sum == 0) 
            return true;
        if(idx >= nums.size() || sum < 0) 
            return false;
        if(dp[idx][sum] != -1)
            return dp[idx][sum];

        bool take = solve(idx+1, nums, sum-nums[idx], dp);
        bool dontTake = solve(idx+1, nums, sum, dp);

        dp[idx][sum] = take || dontTake;
        return dp[idx][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums)
        {
            sum += num;
        }
        if(sum&1) // odd
        {
            return false;
        }
        sum = sum/2;
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        return solve(0, nums, sum, dp);
        
    }
};

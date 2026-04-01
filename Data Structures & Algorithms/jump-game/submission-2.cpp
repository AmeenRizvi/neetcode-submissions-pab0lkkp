class Solution {
    bool solve(int idx, vector<int>& nums, vector<int>&dp )
    {
        if(idx == nums.size()-1)
            return true;
        if(idx >= nums.size())
            return true;
        if(dp[idx] != -1)
            return dp[idx];
        int steps = nums[idx];
        for(int i = 1; i <= steps; i++)
        {
            bool ans = solve(idx+i, nums, dp);
            if(ans)
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solve(0, nums, dp);
        
    }
};

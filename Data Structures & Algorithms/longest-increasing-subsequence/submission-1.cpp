class Solution {
    int solve(int i, int prev_i ,vector<int>& nums, vector<vector<int>>&dp)
    {
        if(i == nums.size())
            return 0;
        if(dp[i][prev_i+1] != -1)
            return dp[i][prev_i+1];

        int p1 = 0, p2 = 0;
        if(prev_i == -1 || nums[i] > nums[prev_i])
            p1 = 1 + solve(i+1, i, nums, dp);

        p2 = solve(i+1, prev_i, nums, dp);

        dp[i][prev_i+1] = max(p1, p2);
        return dp[i][prev_i+1];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+2, -1));
        return solve(0, -1, nums, dp);
        
    }
};

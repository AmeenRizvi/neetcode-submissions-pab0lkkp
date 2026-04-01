class Solution {
    int solve(int i, int n, vector<int>& nums, vector<int>&dp )
    {
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];

        int p1 = nums[i] + solve(i+2, n, nums, dp);
        int p2 = solve(i+1, n, nums, dp);

        return dp[i] = max(p1, p2);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n+1, -1);
        // return solve(0, n, nums, dp);

        vector<int>dp(n+1, 0);
        for(int i = n-1; i >= 0; i--)
        {
            int p1 = 0, p2 = 0;
            if(i+2 < n)
                p1 = dp[i+2];
            p2 = dp[i+1];

            dp[i] = max(nums[i] + p1, p2);
        }
        return dp[0];
    }
};

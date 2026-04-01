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

        // vector<int>dp(n+1, 0);
        int next1 = 0, next2 = 0;
        for(int i = n-1; i >= 0; i--)
        {
            int curr = max(nums[i]+next2, next1);
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
};

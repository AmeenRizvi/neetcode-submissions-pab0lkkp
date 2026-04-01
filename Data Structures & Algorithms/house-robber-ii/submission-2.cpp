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
        if(n == 1)
            return nums[0];
        vector<int>dp1(n+1, -1);
        vector<int>dp2(n+1, -1);

        int ans1 = solve(0, n-1, nums, dp1);
        int ans2 = solve(1, n, nums, dp2);
        
        return max(ans1, ans2);
    }
};

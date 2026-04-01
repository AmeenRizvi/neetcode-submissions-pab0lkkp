class Solution {
    int solve(int i, vector<int>& nums, int &maxSum, bool flag, vector<vector<int>>&dp )
    {
        if(i == nums.size())
            return 0;
        int f = flag ? 1 : 0; 
        if(dp[i][f] != INT_MIN)
            return dp[i][f];

        int sum = max(nums[i], solve(i+1, nums, maxSum, true, dp)+nums[i]);
        maxSum = max(maxSum, sum);
        return dp[i][f] = sum;
    }
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        vector<vector<int>>dp(n+1, vector<int>(2, INT_MIN));
        solve(0, nums, maxSum, false,dp);

        return maxSum;

    }
};

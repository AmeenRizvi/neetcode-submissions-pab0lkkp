class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        vector<int>dp(n+1, INT_MIN);
        dp[n] = 0;

        for(int i = n-1; i >= 0; i--)
        {
            dp[i] = max(dp[i+1] + nums[i], nums[i]);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;

    }
};

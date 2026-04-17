class Solution {
    int n;
    vector<vector<int>>dp;
    int maxSum;
    
    int solve(int i, int sum, int target, vector<int>& nums)
    {
        if(i >= n)
        {
            return sum == target;
        }
        if(dp[i][maxSum + sum] != INT_MIN)
        {
            return dp[i][maxSum + sum];
        }

        int addPath = solve(i+1, sum+nums[i], target, nums);
        int subPath = solve(i+1, sum-nums[i], target, nums);

        return dp[i][maxSum + sum] = addPath + subPath;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        maxSum = accumulate(nums.begin(), nums.end(), 0);
        dp.resize(n, vector<int>(2*maxSum + 1, INT_MIN));

        return solve(0, 0, target, nums);
    }
};

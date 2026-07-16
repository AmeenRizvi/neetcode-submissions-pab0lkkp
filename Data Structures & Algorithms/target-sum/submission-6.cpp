class Solution {
    int totalSum;
    int solve(int i, vector<int>& nums, int sum, int target, vector<vector<int>>&dp)
    {
        if(i == nums.size())
        {
            return sum == target;
        }
        if(dp[i][totalSum + sum] != -1)
        {
            return dp[i][totalSum + sum];
        }

        int op1 = solve(i+1, nums, sum + nums[i], target, dp);
        int op2 = solve(i+1, nums, sum - nums[i], target, dp);

        return dp[i][totalSum + sum] = op1 + op2;

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        totalSum = 0;

        for(int num : nums)
        {
            totalSum += num;
        }

        vector<vector<int>>dp(n+1, vector<int>(2*totalSum+1, -1));
        return solve(0, nums, 0, target, dp);
        
    }
};

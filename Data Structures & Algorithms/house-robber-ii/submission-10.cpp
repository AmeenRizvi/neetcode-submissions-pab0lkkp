class Solution {
    int n;
    int solve(int start, int end, vector<int>& nums )
    {
        vector<int>dp(n+2, 0);

        for(int i = end; i >= start; i--)
        {
            dp[i] = max(dp[i+2] + nums[i], dp[i+1]);
        }
        return dp[start];
    }
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 1) return nums[0];
        
        int a1 = solve(0, n-2, nums);
        int a2 = solve(1, n-1, nums);
        
        return max(a1, a2);
    }
};

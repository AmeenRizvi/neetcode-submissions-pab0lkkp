class Solution {
    int n;
    int solve(int start, int end, vector<int>& nums )
    {
        // vector<int>dp(n+2, 0);
        int next2 = 0;
        int next1 = 0;

        for(int i = end; i >= start; i--)
        {
            // dp[i] = max(dp[i+2] + nums[i], dp[i+1]);
            int curr = max(next2 + nums[i], next1 );

            next2 = next1;
            next1 = curr; 
        }
        return next1;
    }
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int a1 = solve(0, n-2, nums);
        int a2 = solve(1, n-1, nums);
        
        return max(a1, a2);
    }
};

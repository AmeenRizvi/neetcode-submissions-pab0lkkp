class Solution {
private:
    int solve(int st, int en, vector<int>& nums)
    {
        vector<int>dp(nums.size(), 0);

        for(int i = st; i <= en; i++)
        {
            dp[i] = max(  (i-2 < 0 ? 0 : dp[i-2]) + nums[i], ( i-1 < 0 ? 0 : dp[i-1]) );
        }
        return dp[en];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }
        int ans1 = solve(0, n-2, nums);
        int ans2 = solve(1, n-1, nums);
        
        return max(ans1, ans2);
    }
};

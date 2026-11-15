class Solution {
private:
    int solve(int st, int en, vector<int>& nums)
    {
        // dp[i-2]    , dp[i-1]
        int prev2 = 0, prev1 = 0;

        for(int i = st; i <= en; i++)
        {
            //dp[i] = max(  dp[i-2]+nums[i] , dp[i-1] );
            int curr = max(prev2 + nums[i], prev1);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
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

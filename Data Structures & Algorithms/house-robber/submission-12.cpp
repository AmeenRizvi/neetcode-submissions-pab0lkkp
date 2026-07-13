class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n+2, 0);
        int next2 = 0, next1 = 0;

        for(int i = n-1; i >= 0; i--)
        {
            // dp[i] = max( dp[i+2] + nums[i], dp[i+1] );
            int curr = max( next2 + nums[i], next1 );

            next2 = next1;
            next1 = curr;
        }
        return next1;
        
    }
};

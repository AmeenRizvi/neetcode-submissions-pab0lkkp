class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
    
        vector<unordered_map<int,int>>dp(n+1);
        dp[n][0] = 1;

        for(int i = n-1; i >= 0; i--)
        {
            for(auto &[prevSum, count] : dp[i+1])
            {
                dp[i][prevSum + nums[i]] += count;
                dp[i][prevSum - nums[i]] += count;
            }
        }
        return dp[0][target];


        
    }
};

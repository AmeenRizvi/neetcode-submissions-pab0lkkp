class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        // 2D dp - index and sum
        unordered_map<int,int>dp;
        dp[0] = 1;  

        for(int num : nums)
        {
            unordered_map<int,int>nextDp;
            for(auto &p : dp)
            {
                int total = p.first;
                int count = p.second;

                nextDp[total + num] += count;
                nextDp[total - num] += count;
            }
            dp = nextDp;
        }

        // Time complexity : O(n*sum)
        // Space complexity : O(sum)

        return dp[target];
    }
};

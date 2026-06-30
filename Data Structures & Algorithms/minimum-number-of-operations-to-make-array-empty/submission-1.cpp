class Solution {
    int dfs(int count, vector<int>&dp)
    {
        if(count < 0)
        {
            return INT_MAX;
        }
        if(count == 0)
        {
            return 0;
        }
        if(dp[count] != -1)
        {
            return dp[count];
        }

        int ops = min( dfs(count-2, dp) , dfs(count-3, dp) );
        return dp[count] = ops == INT_MAX ? ops : 1 + ops;
    }
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>freq;

        for(int num : nums)
        {
            freq[num]++;
        }
        int n = nums.size();
        int ans = 0;

        for(auto &p : freq)
        {
            vector<int>dp(p.second+1, -1);
            int op = dfs(p.second, dp);
            if(op == INT_MAX)
            {
                return -1;
            }
            ans += op;
        }
        return ans;
    }
};
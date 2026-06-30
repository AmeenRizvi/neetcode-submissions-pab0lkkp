class Solution {
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
            vector<int>dp(p.second+1, 1e9);
            dp[0] = 0;
            for(int i = 1; i <= p.second; i++ )
            {
                int p1 = i-2 < 0 ? 1e9 : dp[i-2];
                int p2 = i-3 < 0 ? 1e9 : dp[i-3];

                int ops = min(p1, p2);
                dp[i] = 1 + ops;
                
            }
            if(dp[p.second] >= 1e9)
            {
                return -1;
            }
            ans += dp[p.second];
        }
        return ans;
    }
};
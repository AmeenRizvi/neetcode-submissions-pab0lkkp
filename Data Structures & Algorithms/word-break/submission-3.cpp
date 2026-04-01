class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n+1, 0);
        dp[n] = 1;

        for(int i = n-1; i>= 0; i--)
        {
            for(const auto& w : wordDict)
            {
                if(dp[i])
                {
                    break;
                }
                if((i+w.size()) <= n && s.substr(i, w.size())==w  )
                {
                    dp[i] = dp[i+w.size()];
                }
                
            }
        }
        return dp[0];
    }
};

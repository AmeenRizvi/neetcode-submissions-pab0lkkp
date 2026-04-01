class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.size()+1, 0);
        dp[s.size()] = 1;

        for(int i = s.size()-1; i >= 0; i--)
        {
            if(s[i] == '0')
                dp[i] = 0;
            else
            {
                int p1 = 0, p2 = 0;
                p1 = dp[i+1];
                if(i < s.size()-1)
                {
                    if(s[i] == '1' || s[i]=='2' && s[i+1] < '7')
                        p2 = dp[i+2];
                }
                dp[i] = p1+p2;
            }
        }
        return dp[0];
        
    }
};

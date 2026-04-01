class Solution {
    int solve(int i, string s, vector<int>&dp)
    {
        if(i == s.size() )
            return 1;
        if(s[i]=='0')
            return 0;
        if(dp[i] != -1)
            return dp[i];

        int p2 = 0;
        int p1 = solve(i+1, s, dp);
        if(i < s.size()-1)
        {
            if(s[i] == '1' || s[i] == '2' && s[i+1] < '7')
                p2 = solve(i+2, s, dp);
        }
        

        return dp[i] = p1+p2;
    }
public:
    int numDecodings(string s) {
        vector<int>dp(s.size()+1, -1);
        return solve(0, s, dp);
        
    }
};

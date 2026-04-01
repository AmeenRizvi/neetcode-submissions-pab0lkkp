class Solution {
public:
    int numDecodings(string s) {
        int dp = 0, dp2 = 0, dp1 = 1;

        for(int i = s.size()-1; i >= 0; i--)
        {
            if(s[i] == '0')
                dp = 0;
            else
            {
                int p1 = 0, p2 = 0;
                p1 = dp1;
                if(i < s.size()-1)
                {
                    if(s[i] == '1' || (s[i]=='2' && s[i+1] < '7'))
                        p2 = dp2;
                }
                dp = p1+p2;

                
            }
            dp2 =dp1;
            dp1 = dp;
            dp = 0;
        }
        return dp1;
        
    }
};

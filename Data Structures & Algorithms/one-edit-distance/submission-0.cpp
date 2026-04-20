class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size(), m = t.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        for(int j = 0; j <= m; j++)
        {
            dp[n][j] = m-j;
        }

        for(int i = 0; i <= n; i++)
        {
            dp[i][m] = n-i;
        }

        for(int i = n-1; i >= 0; i--)
        {
            for(int j = m-1; j >= 0; j--)
            {
                if(s[i] == t[j])
                {
                    dp[i][j] = dp[i+1][j+1];
                    continue;
                }
                else
                {
                    int op1 = 1 + dp[i][j+1];
                    int op2 = 1 + dp[i+1][j];
                    int op3 = 1 + dp[i+1][j+1];

                    dp[i][j] = min(op1, min(op2, op3));
                }
            }
        }
        return dp[0][0] == 1;
        
    }
};

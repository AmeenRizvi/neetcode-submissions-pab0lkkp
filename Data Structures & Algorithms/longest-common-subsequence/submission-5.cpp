class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        // vector<int>curr(m+1, 0);
        // vector<int>forw(m+1, 0);
        vector<int>dp(m+1, 0);
        for(int i = n-1; i >= 0; i--)
        {
            int prev_diag = 0;
            for(int j = m-1; j >= 0; j--)
            {
                int temp = dp[j];
                if(text1[i] == text2[j])
                    dp[j] = 1 + prev_diag; 
                else
                {
                    dp[j] = max(temp, dp[j+1]);
                }
                prev_diag = temp;
            }
            
        }
        return dp[0];
        
    }
};

class Solution {
    int solve(int i, int j, string s1, string s2, vector<vector<int>>&dp)
    {
        if(i == s1.size() || j == s2.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int dontTake1 = 0, dontTake2 = 0;
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + solve(i+1, j+1, s1, s2, dp);
        
        dontTake1 = solve(i+1, j, s1, s2, dp);
        dontTake2 = solve(i, j+1, s1, s2, dp);
        return dp[i][j] = max(dontTake1, dontTake2);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        // if(n < m)
        //     swap(text1, text2);
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(0 ,0, text1, text2, dp);
        
    }
};

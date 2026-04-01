class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int>curr(m+1, 0);
        vector<int>forw(m+1, 0);
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = m-1; j >= 0; j--)
            {
                if(text1[i] == text2[j])
                    curr[j] = 1 + forw[j+1];
                else
                {
                    curr[j] = max(forw[j], curr[j+1]);
                }
            }
            forw = curr;
        }
        return forw[0];
        
    }
};

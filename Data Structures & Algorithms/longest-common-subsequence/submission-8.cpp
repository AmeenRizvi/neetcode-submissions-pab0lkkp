class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        // vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        vector<int>row(m+1, 0);
        vector<int>nextRow(m+1, 0);

        for(int i = n-1; i >= 0; i--)
        {
            for(int j = m-1; j >= 0; j--)
            {
                if(text1[i] == text2[j])
                {
                    row[j] = 1 + nextRow[j+1];
                }
                else
                {
                    row[j] = max(row[j+1], nextRow[j]);
                }
            }
            nextRow = row;
        }
        return row[0];
        
    }
};

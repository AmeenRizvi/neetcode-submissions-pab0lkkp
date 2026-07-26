class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));


        for(int i = n-1; i >= 0; i--)
        {
            for(int j = i; j < n; j++)
            {
                bool even = (j-i)%2 == 0;
                int left = even ? piles[i] : 0;
                int right = even ? piles[j] : 0;
                if(i == j)
                {
                    dp[i][j] = left;
                }
                else
                {
                    dp[i][j] = max( dp[i+1][j] + left, dp[i][j-1] + right );
                }
            }
        }

        return dp[0][n-1];
        
    }
};
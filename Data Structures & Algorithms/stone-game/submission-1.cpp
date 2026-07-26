class Solution {
    int solve(int i, int j, vector<int>& piles, vector<vector<int>>&dp)
    {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];


        int op1 = piles[i] - solve(i+1, j, piles, dp);
        int op2 = piles[j] - solve(i, j-1, piles, dp);

        return dp[i][j] = max(op1, op2);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++)
        {
            dp[i][i] = piles[i];
        }
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
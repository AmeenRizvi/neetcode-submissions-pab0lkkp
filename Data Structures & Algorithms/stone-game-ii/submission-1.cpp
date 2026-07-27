class Solution {
    int solve(int i, int M, vector<int>& piles, vector<int>&suffixSum, vector<vector<int>>&dp)
    {
        if(i >= piles.size()) return 0;
        if(i + 2*M >= piles.size()) return suffixSum[i];
        if(dp[i][M] != -1) return dp[i][M];

        int ans = 0;
        for(int X = 1; X <= 2*M; X++)
        {
            ans = max(ans, suffixSum[i] - solve(i+X, max(M, X), piles,suffixSum, dp ) );
        }
        return dp[i][M] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int>suffixSum(n, 0);
        int pilesCollected = 0;
        for(int i = n-1; i >= 0; i--)
        {
            pilesCollected += piles[i];
            suffixSum[i] = pilesCollected;
        }

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        // return solve(0, 1, piles, suffixSum, dp);

        for(int i = n-1; i >= 0; i--)
        {

            for(int M = 1; M <= n; M++)
            {
                for(int X = 1; X <= 2*M; X++)
                {
                    if(i+X > n) break;
                    dp[i][M] = max(dp[i][M], suffixSum[i] - dp[i+X][max(M, X)]);
                }
            }
        }
        return dp[0][1];
        
    }
};
class Solution {
    bool isSquare(int num)
    {
        for(int i = 1; i <= sqrt(num); i++)
        {
            if(i*i == num)
            {
                return true;
            }
        }
        return false;

    }
    int solve(int n, vector<int>&dp)
    {
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = 1e9;

        for(int i = n; i > 0; i--)
        {
            if( isSquare(i) )
            {
                int temp = solve(n - i, dp);
                if(temp != -1)
                {
                    ans = min(ans, 1 + temp );
                }
            }

        }
        return dp[n] = ans >= 1e9 ? -1 : ans;
    }
public:
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
};
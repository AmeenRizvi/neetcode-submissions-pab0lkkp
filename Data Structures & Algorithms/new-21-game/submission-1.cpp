class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double>dp(n+1, 0.0);
        dp[0] = 1;

        for(int p = 1; p <= n; p++)
        {
            for(int draw = 1; draw <= maxPts; draw++)
            {
                if(p-draw >= 0 && p-draw < k)
                {
                    dp[p] += dp[p-draw]/maxPts;
                }
            }
        }

        double ans = 0.0;
        for(int i = k; i <= n; i++)
        {
            ans += dp[i];
        }
        return ans;
        
    }
};
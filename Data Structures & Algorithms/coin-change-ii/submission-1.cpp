class Solution {
    int solve(int idx, int amount, vector<int>& coins, vector<vector<int>>&dp)
    {
        if(amount == 0) return 1;
        if(idx < 0 || amount < 0) return 0;
        if(dp[idx][amount] != -1) return dp[idx][amount];

        int ans = 0;
        for(int i = idx; i >= 0; i--)
        {
            int tmp = solve(i, amount - coins[i], coins, dp);
            ans += tmp;
        }
        return dp[idx][amount] = ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return solve(n-1, amount, coins, dp);
        
    }
};

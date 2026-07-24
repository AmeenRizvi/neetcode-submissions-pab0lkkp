class Solution {
    unordered_map<int,int>dp;
    int solve(int n, int k)
    {
        if(n == 1) return k;
        if(n == 2) return k*k;
        if(dp.find(n) != dp.end()) return dp[n];

        int op1 = solve(n-1, k);
        int op2 = solve(n-2, k);

        return dp[n] = (k-1)*(op1 + op2);
    }
public:
    int numWays(int n, int k) {
        // vector<int>dp(n+1, -1);
        return solve(n, k);
        
    }
};

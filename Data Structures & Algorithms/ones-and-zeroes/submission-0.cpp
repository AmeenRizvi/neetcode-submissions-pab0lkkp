class Solution {
    int solve(int i, vector<vector<int>>&arr, int m, int n, vector<vector<vector<int>>>&dp)
    {
        if(i >= arr.size() || m < 0 || n < 0)
        {
            return 0;
        }
        if(dp[i][m][n] != -1)
        {
            return dp[i][m][n];
        }

        int curr_m = arr[i][0];
        int curr_n = arr[i][1];

        int take = 0;
        if(m - curr_m >= 0 && n - curr_n >= 0)
        {
            take = 1 + solve(i+1, arr, m - curr_m, n - curr_n, dp);
        }
        int dontTake = solve(i+1, arr, m, n, dp);

        return dp[i][m][n] =  max(take, dontTake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vector<int>>arr;
        for(auto &str : strs)
        {
            int zeroes = 0, ones = 0;
            for(char c : str)
            {
                if(c == '0') zeroes++;
                if(c == '1') ones++;
            }
            arr.push_back({zeroes, ones});
        }


        vector<vector<vector<int>>>dp(N+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(0, arr, m, n, dp);
        
    }
};
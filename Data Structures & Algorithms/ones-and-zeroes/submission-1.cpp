class Solution {
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


        vector<vector<vector<int>>>dp(N+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        // return solve(0, arr, m, n, dp);

        for(int i = N-1; i >= 0; i--)
        {
            for(int Mi = 0; Mi <= m; Mi++)
            {
                for(int Ni = 0; Ni <= n; Ni++)
                {
                    int curr_m = arr[i][0], curr_n = arr[i][1];
                    int take = 0;
                    if(Mi - curr_m >= 0 && Ni - curr_n >= 0)
                    {
                        take = 1 + dp[i+1][Mi-curr_m][Ni-curr_n];
                    }
                    int dontTake = dp[i+1][Mi][Ni];
                    dp[i][Mi][Ni] = max(take, dontTake);
                }
            }
        }
        return dp[0][m][n];
        
    }
};
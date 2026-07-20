class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        
        unordered_map<int,int>mp;
        mp.insert({0, 1});
        mp.insert({1, 7});
        mp.insert({2, 30});

        vector<int>dp(n+1, 0);

        for(int i = n-1; i >= 0; i--)
        {
            int ans = INT_MAX;
            for(int j = 0; j < costs.size(); j++)
            {
                int nextBookingDate = days[i] + mp[j];
                int next_i = i;

                while(next_i < days.size() && days[next_i] < nextBookingDate)
                {
                    next_i++;
                }
                int temp = dp[next_i] + costs[j];
                ans = min(ans, temp);
            }
            dp[i] = ans;
        }
        return dp[0];


    }
};
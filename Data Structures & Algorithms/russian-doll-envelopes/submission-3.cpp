class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b)
        {
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        });
        
        vector<int>heights(n);
        for(int i = 0; i < n; i++)
        {
            heights[i] = envelopes[i][1];
        }

        vector<int>dp;
        dp.push_back(heights[0]);
        int ans = 1;
        for(int i = 1; i < n; i++)
        {
            if(dp.back() < heights[i])
            {
                dp.push_back(heights[i]);
                ans++;
                continue;
            }
            int idx = lower_bound(dp.begin(), dp.end(), heights[i])-dp.begin();
            dp[idx] = heights[i];
        }
        return ans;
    }
};
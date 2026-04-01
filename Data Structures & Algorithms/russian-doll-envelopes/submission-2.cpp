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

        vector<int>LIS(n, 1);
        int ans = 0;
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = i+1; j < n; j++)
            {
                if(heights[i] < heights[j])
                {
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
            ans = max(ans, LIS[i]);
        }
        return ans;
    }
};
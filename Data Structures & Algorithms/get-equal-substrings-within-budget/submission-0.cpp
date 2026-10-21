class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int>cost(n, 0);

        for(int i = 0; i < n; i++)
        {
            cost[i] = abs(s[i] - t[i]);
        }

        int l = 0, r = 0, maxLen = 0;
        while(r < n)
        {
            maxCost -= cost[r];
            while(maxCost < 0)
            {
                maxCost += cost[l];
                l++;
            }
            int len = r-l+1;
            maxLen = max(maxLen, len);
            r++;
        }
        return maxLen;

    }
};

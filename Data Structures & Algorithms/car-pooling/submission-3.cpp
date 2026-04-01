class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int l = INT_MAX, r = INT_MIN;

        for(const auto& trip : trips)
        {
            l = min(l, trip[1]);
            r = max(r, trip[2]);
        }

        int n = r-l+1;
        vector<int>passChange(n+1, 0);

        for(const auto& trip : trips)
        {
            passChange[trip[1] - l] += trip[0];
            passChange[trip[2] - l] -= trip[0];
        }

        int curPass = 0;
        for(int change : passChange)
        {
            curPass += change;
            if(curPass > capacity)
            {
                return false;
            }
        }

        return true;

    }
};
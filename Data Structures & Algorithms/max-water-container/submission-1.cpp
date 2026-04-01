class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), res = INT_MIN;

        int l = 0, r = n-1;
        while(l < r)
        {
            int h = min(heights[l], heights[r]);
            int w = r-l;
            res = max(res, h*w);

            if(heights[l] < heights[r])
                l++;
            else
                r--;
        }
        return res == INT_MIN ? 0 : res;

        
    }
};

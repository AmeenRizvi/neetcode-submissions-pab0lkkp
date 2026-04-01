class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), res = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int h = min(heights[i], heights[j]);
                int w = j-i;
                res = max(res, h*w);
            }
        }
        return res == INT_MIN ? 0 : res;
        
    }
};

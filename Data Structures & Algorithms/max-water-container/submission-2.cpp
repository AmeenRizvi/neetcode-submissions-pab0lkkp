class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0, right = n-1;
        int maxArea = 0;

        while(left < right)
        {
            int w = right - left;
            int h = min(heights[left], heights[right]);
            int area = w*h;
            maxArea = max(maxArea, area);

            if(heights[left] < heights[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea;
        
    }
};

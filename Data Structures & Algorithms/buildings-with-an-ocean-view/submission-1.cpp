class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int>ans;
        ans.push_back(n-1);

        for(int i = n-2; i>= 0; i--)
        {
            if(heights[i] > heights[ans.back()])
            {
                ans.push_back(i);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
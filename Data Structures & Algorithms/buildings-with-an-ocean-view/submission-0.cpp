class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<pair<int,int>>st;
        int n = heights.size();
        for(int i = n-1; i >= 0; i--)
        {
            if(i == n-1 || heights[i] > st.top().first)
            {
                st.push({heights[i], i});
            }
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top().second);
            st.pop();
        }
        return ans;
        
    }
};
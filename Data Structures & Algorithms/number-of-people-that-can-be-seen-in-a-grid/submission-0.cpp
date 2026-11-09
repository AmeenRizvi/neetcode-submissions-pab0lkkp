class Solution {
public:
    vector<vector<int>> seePeople(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>>ans(m, vector<int>(n, 0));

        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < (i == 0 ? m : n); j++)
            {
                stack<int>st;
                for(int pos = (i == 0 ? n : m)-1; pos >= 0; pos--)
                {
                    int r = i == 0 ? j : pos, c = i == 0 ? pos : j, h = heights[r][c];
                    while(!st.empty() && st.top() < h)
                    {
                        ans[r][c]++;
                        st.pop();
                    }
                    if(!st.empty() )
                    {
                        ans[r][c]++;
                        if(st.top() == h)
                        {
                            st.pop();
                        }
                    }
                    st.push(h);

                }
            }
        }
        return ans;

    }
};

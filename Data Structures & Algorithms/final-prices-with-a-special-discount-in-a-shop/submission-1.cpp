class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int>st;
        vector<int>ans(prices.begin(), prices.end());

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && prices[st.top()] >= prices[i])
            {
                int prev_i = st.top();
                st.pop();
                ans[prev_i] -= prices[i];
            }
            st.push(i);
        }
        return ans;

    }
};

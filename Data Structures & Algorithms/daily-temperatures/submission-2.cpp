class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        stack<int>st;
        vector<int>result(n, 0);

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                int days = i-st.top();
                result[st.top()] = days;
                st.pop();
            }
            st.push(i);
        }
        return result;
        
    }
};

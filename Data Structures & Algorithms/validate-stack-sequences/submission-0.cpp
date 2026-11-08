class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int>st;
        int l = 0;

        for(int r = 0;r < n; r++)
        {
            st.push(pushed[r]);
            while(!st.empty() && popped[l] == st.top() )
            {
                st.pop();
                l++;
            }
        }
        return l == popped.size();

    }
};

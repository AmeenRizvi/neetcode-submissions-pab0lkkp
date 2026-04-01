class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int>st;
        for(auto &str : operations)
        {
            if(str == "+")
            {
                int prev1 = st.top();
                st.pop();
                int newNum = prev1 + st.top();
                st.push(prev1);
                st.push(newNum);
            }
            else if(str == "D")
            {
                int prev = st.top();
                st.push(2*prev);
            }
            else if(str == "C")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(stoi(str));
            }
        }

        int sum = 0;
        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
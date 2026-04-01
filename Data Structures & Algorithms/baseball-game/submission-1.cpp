class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int>st;
        int res = 0;
        for(auto &str : operations)
        {
            if(str == "+")
            {
                int prev1 = st.top();
                st.pop();
                int newNum = prev1 + st.top();
                st.push(prev1);
                st.push(newNum);
                res += newNum;
            }
            else if(str == "D")
            {
                int prev = st.top();
                st.push(2*prev);
                res += 2*prev;
            }
            else if(str == "C")
            {
                if(!st.empty())
                {
                    res -= st.top();
                    st.pop();
                }
            }
            else
            {
                st.push(stoi(str));
                res += stoi(str);
            }
        }

        return res;
    }
};
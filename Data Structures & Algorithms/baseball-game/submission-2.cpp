class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;

        for(auto &str : operations)
        {
            if(str == "+")
            {
                int num1 = st.top();
                st.pop();
                int sum = num1 + st.top();

                st.push(num1);
                st.push(sum);
            }
            else if(str == "D")
            {
                st.push(2*st.top());
            }
            else if(str == "C")
            {
                st.pop();
            }
            else
            {
                st.push(stoi(str));
            }
        }

        int ans = 0;
        while(!st.empty() )
        {
            ans += st.top();
            st.pop();
        }

        return ans;
        
    }
};
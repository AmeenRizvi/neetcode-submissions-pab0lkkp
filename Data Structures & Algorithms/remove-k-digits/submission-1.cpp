class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;

        for(char c : num)
        {
            while(!st.empty() && st.top() > c && k > 0)
            {
                st.pop();
                k--;
            }
            st.push(c);
        }

        while(k > 0)
        {
            st.pop();
            k--;
        }

        string temp = "";
        while(!st.empty() )
        {
            temp += st.top();
            st.pop();
        }

        reverse(temp.begin(), temp.end());
        
        int i = 0, n = temp.size();
        while(i < n && temp[i] == '0')
        {
            i++;
        }
        string ans = "";
        while(i < n)
        {
            ans += temp[i++];
        }
        return ans == "" ? "0" : ans;

    }
};

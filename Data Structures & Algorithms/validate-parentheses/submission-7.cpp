class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>mp;
        mp.insert({')','(' });
        mp.insert({'}', '{'});
        mp.insert({']', '['});

        stack<int>st;

        for(char c : s)
        {
            if(c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if(!st.empty() && st.top() == mp[c] )
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return !st.size();

        
    }
};

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
                if(st.empty() || ( !st.empty() && st.top() != mp[c] ))
                {
                    return false;
                }
                st.pop();
            }
        }

        return st.size() == 0 ? true : false;

        
    }
};

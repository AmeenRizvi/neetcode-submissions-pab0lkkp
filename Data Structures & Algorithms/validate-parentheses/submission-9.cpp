class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<int>st;

        unordered_map<char,char>mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty() ||  (!st.empty() && mp[s[i]] != st.top() ) )
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty() ? true : false;;

        
    }
};

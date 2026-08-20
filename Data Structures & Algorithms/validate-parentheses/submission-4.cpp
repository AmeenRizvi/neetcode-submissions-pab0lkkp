class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char>st;
        unordered_map<char,char>mp;
        mp.insert({ ')', '(' });
        mp.insert({ '}', '{' });
        mp.insert({ ']', '[' });


        for(int i = 0; i < n; i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty() || st.top() != mp[s[i] ])
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

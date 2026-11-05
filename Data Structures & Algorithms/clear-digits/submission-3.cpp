class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        string ans = "";

        for(int i = 0; i < n; i++)
        {
            if((s[i])-'0' >= 0 && s[i]-'0' <=9 )
            {                
                ans.pop_back();            
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;

    }
};

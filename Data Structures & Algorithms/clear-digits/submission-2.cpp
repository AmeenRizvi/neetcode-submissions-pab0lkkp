class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        string ans = "";

        for(int i = 0; i < n; i++)
        {
            if(isdigit(s[i]) )
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

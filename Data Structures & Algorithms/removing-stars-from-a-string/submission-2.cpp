class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        if(n == 1) return s;
        
        string ans = "";

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '*')
            {
                ans.pop_back();
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;

    }
};

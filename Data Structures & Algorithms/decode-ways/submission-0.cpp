class Solution {
    int solve(int i, string s)
    {
        if(i == s.size() )
            return 1;
        if(s[i]=='0')
            return 0;

        int p2 = 0;
        int p1 = solve(i+1, s);
        if(i < s.size()-1)
        {
            if(s[i] == '1' || s[i] == '2' && s[i+1] < '7')
                p2 = solve(i+2, s);
        }
        

        return p1+p2;
    }
public:
    int numDecodings(string s) {
        return solve(0, s);
        
    }
};

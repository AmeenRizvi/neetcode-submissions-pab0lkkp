class Solution {
    void solve(int l, int r, string &s, int &count)
    {
        int n = s.size();
        while(l >= 0 && r < n && s[l] == s[r])
        {
            count++;
            l--;
            r++;
        }
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for(int i = 0; i < n; i++ )
        {
            solve(i, i, s, count);
            solve(i, i+1, s, count);
        }
        return count;
        
    }
};

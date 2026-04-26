class Solution {
    int n;
    void expandAroundCenter(int l, int r, int &count, string s)
    {
        while(l >= 0 && r < n && s[l] == s[r] )
        {
            l--;
            r++;
            count++;
        }
    }
public:
    int countSubstrings(string s) {
         n = s.size();
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            expandAroundCenter(i, i, count, s);    // odd
            expandAroundCenter(i, i+1, count, s);  // even
        }
        return count;
        
    }
};

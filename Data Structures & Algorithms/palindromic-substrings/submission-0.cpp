class Solution {
    void expandAroundCenter(int l, int r, string s, int &count)
    {
        while(l >= 0 && r < s.size() && s[l]==s[r])
        {
            count++;
            l--;
            r++;
        }
    }
public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;

        for(int i = 0; i < n; i++)
        {
            expandAroundCenter(i, i, s, count);
            expandAroundCenter(i, i+1, s, count);
        }
        return count;
    }
};

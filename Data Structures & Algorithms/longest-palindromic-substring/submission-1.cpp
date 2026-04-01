class Solution {
    int solve(int l, int r, string s)
    {
        int n = s.size();
        while(l >= 0 && r < n && s[l]==s[r])
        {
            l--;
            r++;
        }
        return r-l-1;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0, startIdx = 0;
        for(int i = 0; i < n; i++)
        {
            int odd = solve(i, i, s);
            int even = solve(i, i+1, s);

            int len = max(odd, even);
            if(len > maxLen)
            {
                maxLen = len;
                startIdx = i-(len-1)/2;
            }
        }
        
        return maxLen == 0 ? "" : s.substr(startIdx, maxLen);
        
    }
};

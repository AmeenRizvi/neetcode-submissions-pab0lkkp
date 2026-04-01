class Solution {
    int palindrome(int l, int r, string s)
    {
        while(l >= 0 && r < s.size() && s[l]==s[r])
        {
            l--;
            r++;
        }
        return r-l-1;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = -1,  idx = -1;
        for(int i = 0; i < n; i++)
        {
            int oddLen = palindrome(i, i, s);
            int evenLen = palindrome(i, i+1, s);

            int len = max(oddLen, evenLen);
            if(len > maxLen)
            {
                maxLen = len;
                idx = i - (maxLen-1)/2;
            }
        }
        return s.substr(idx, maxLen );
        
    }
};

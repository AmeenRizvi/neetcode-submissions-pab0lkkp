class Solution {
    bool alpnum(char c)
    {
        if( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
        (c>= '0' && c <= '9') )
            return true;
        return false;
    }
public:
    bool isPalindrome(string s) {

        int l = 0, r = s.size()-1;

        while(l <= r)
        {
            while(l < r &&  !alpnum(s[l]))
            {
                l++;
            }
            while(r > l && !alpnum(s[r]) )
            {
                r--;
            }
            if(tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }

        return true;
        
    }
};

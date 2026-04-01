class Solution {
    bool checkPalindrome(string temp)
    {
        int l = 0, r = temp.size()-1;
        while(l < r)
        {
            if(temp[l] != temp[r] )
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n-1;

        while(l < r)
        {
            if(s[l] != s[r])
            {
                return checkPalindrome(s.substr(0, l) + s.substr(l+1) ) || 
                checkPalindrome( s.substr(0,r) + s.substr(r+1) );    
            }
            l++;
            r--;
        }
        return true;
    }
};
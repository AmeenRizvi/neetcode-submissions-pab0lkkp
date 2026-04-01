class Solution {
    bool checkPalindrome(string &temp)
    {
        int l = 0, r = temp.size()-1;
        while(l <= r)
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
        for(int i = 0; i < n; i++)
        {
            string temp = s.substr(0, i) + s.substr(i+1);
            bool ans = checkPalindrome(temp);
            if(ans) return true;
        }
        return false;
    }
};
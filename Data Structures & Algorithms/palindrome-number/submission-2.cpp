class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x%10 == 0 && x!=0))
            return false;
        
        int n = x;
        int res = 0;
        while(n > res)
        {
            int r = n%10;
            res = res*10+r;
            n = n/10;
        }

        return res == n || res/10 == n;
    }
};
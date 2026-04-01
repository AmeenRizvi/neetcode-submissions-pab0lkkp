class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        int n = x;
        long long res = 0;
        while(n != 0)
        {
            int r = n%10;
            res = res*10+r;
            n = n/10;
        }

        return (int)res == x;
    }
};
class Solution {
public:
    bool isPerfectSquare(int num) {

        long long l = 0, r = num, ans = 0;
        while(l <= r)
        {
            long long mid = r+(l-r)/2;
            if(num == mid*mid)
                return true;
            else if(num > mid*mid)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
        
    }
};
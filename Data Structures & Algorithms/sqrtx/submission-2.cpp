class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int l = 1, r = x;
        long long ans = 1;
        while(l <= r)
        {
            long long mid = r + (l-r)/2;
            if(mid*mid <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
        
    }
};
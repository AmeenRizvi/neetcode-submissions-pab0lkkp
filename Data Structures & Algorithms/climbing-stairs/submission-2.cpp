class Solution {
public:
    int climbStairs(int n) {
        int next1 = 1, next2 = 1;
        for(int i = n-2; i >= 0; i--)
        {
            int curr = next1 + next2;
            
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
};

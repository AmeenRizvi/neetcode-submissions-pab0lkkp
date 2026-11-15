class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }
        vector<int>dp1(n, 0);
        vector<int>dp2(n, 0);

        for(int i = 0; i <= n-2; i++)
        {
            dp1[i] = max( (i-2 >= 0 ? dp1[i-2] : 0 ) + nums[i] , 
                          (i-1 >= 0 ? dp1[i-1] : 0) );
        }

        for(int i = 1; i <= n-1; i++)
        {
            dp2[i] = max( (i-2 >= 0 ? dp2[i-2] : 0 ) + nums[i] , 
                          (i-1 >= 0 ? dp2[i-1] : 0) );
        }

        return max(dp1[n-2], dp2[n-1]);
        
    }
};

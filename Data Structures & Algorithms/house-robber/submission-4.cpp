class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }
        if(n == 2)
        {
            return max(nums[0], nums[1]);
        }
        vector<int>dp(n+1, 0);

        int prev2 = nums[n-1];
        int prev1 = nums[n-2];
        for(int i = n-3; i >= 0; i--)
        {

            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

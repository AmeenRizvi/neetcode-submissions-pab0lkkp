class Solution {
    int helper(vector<int>& nums, int goal)
    {
        if(goal < 0) return 0;
        int n = nums.size();
        int l = 0, sum = 0, ans = 0;

        for(int r = 0; r < n; r++)
        {
            sum += nums[r];
            while(sum > goal)
            {
                sum -= nums[l];
                l++;
            }
            ans += (r-l+1);
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
        
        
    }
};
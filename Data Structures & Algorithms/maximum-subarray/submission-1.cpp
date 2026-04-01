class Solution {
    int solve(int i, vector<int>& nums, int &maxSum )
    {
        if(i == nums.size())
            return 0;
        
        int sum = max(nums[i], solve(i+1, nums, maxSum)+nums[i]);
        maxSum = max(maxSum, sum);
        return sum;
    }
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        solve(0, nums, maxSum);

        return maxSum;

    }
};

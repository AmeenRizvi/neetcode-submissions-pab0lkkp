class Solution {
    int helper(vector<int>nums)
    {
        int prev2 = 0, prev1 = 0;
        for(int i = 0; i < nums.size();i++)
        {
            int curr = max(prev2 + nums[i], prev1 );
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1; 
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int>nums1(nums.begin()+1, nums.end());
        vector<int>nums2(nums.begin(), nums.end()-1);

        int ans1 = helper(nums1);
        int ans2 = helper(nums2);

        return max(ans1, ans2);
        
    }
};

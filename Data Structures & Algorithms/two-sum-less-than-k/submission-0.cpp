class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(nums[i] + nums[j] < k)
                {
                    ans = max(ans, nums[i] + nums[j]);
                }
            }
        }
        return ans;
    }
};

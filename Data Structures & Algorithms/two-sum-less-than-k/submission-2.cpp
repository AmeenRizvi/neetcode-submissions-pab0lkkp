class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = -1;

        
        int l = 0, r = n-1;
        while(l < r)
        {
            
            if(nums[l] + nums[r] < k)
            {
                ans = max(ans, nums[l] + nums[r]);
                l++;
            }
            else
            {
                r--;                
            }

        }
        return ans;
        
    }
};

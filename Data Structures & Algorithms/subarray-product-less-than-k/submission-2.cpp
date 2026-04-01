class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, l = 0, n = nums.size();
        long long prod = 1;

        for(int r = 0; r < n; r++)
        {
            prod *= nums[r];
            while(l <= r && prod >= k)
            {
                prod = prod / nums[l];
                l++;
            }
            ans += (r-l+1);
        }
        return ans;
        
    }
};
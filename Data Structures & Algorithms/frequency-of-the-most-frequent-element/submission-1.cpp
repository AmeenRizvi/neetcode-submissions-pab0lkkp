class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = 0, ans = 0, total = 0;

        while(r < n)
        {
            total += nums[r];

            while(nums[r]*(r-l+1) > total + k)
            {
                total -= nums[l];
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
        
    }
};
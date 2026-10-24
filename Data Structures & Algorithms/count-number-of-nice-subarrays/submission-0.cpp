class Solution {
private:
    int slidingWindow(vector<int>& nums, int k)
    {
        
        int n = nums.size();
        int l = 0, r = 0, count = 0, ans = 0;

        while(r < n)
        {
            if(nums[r] % 2 == 1)
            {
                count++;
            }
            while(count > k)
            {
                if(nums[l] % 2 == 1)
                {
                    count--;
                }
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;

    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        int ans = slidingWindow(nums, k) - slidingWindow(nums, k-1);
        return ans;

    }
};

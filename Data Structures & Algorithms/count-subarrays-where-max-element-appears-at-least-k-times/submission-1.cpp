class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = 0;
        for(int i = 0; i < n; i++)
        {
            maxVal = max(maxVal, nums[i]);
        }

        long long l = 0, r = 0, count = 0; 
        long long ans = 0;
        while(r < n)
        {
            if(nums[r] == maxVal)
            {
                count++;
            }
            while( count >= k)
            {
                ans += n-r;
                if(nums[l] == maxVal)
                {
                    count--;
                }
                l++;
            }
            r++;
        }
        return ans;

    }
};

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = -1;

        for(int i = 0; i < n-1; i++)
        {
            int nums1 = nums[i];
            int l = i+1, r = n-1;
            while(l <= r)
            {
                int mid = (l+r)/2;
                if(nums[mid] + nums1 < k)
                {
                    ans = max(ans, nums[mid] + nums1);
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }

        }
        return ans;
        
    }
};

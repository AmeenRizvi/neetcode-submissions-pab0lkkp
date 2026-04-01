class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        int res = nums.size();
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] >= target)
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
        
        
    }
};
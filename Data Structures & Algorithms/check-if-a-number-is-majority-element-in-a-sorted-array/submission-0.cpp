class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n;

        while(l < r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        int lb = l;

        l = 0;
        r = n;

        while(l < r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] > target)
                r = mid;
            else
                l = mid + 1;
        }
        
        int ub = l;

        return ub-lb > n/2;
    }
};

class Solution {
    int binarySearch(vector<int>&nums, int target, bool leftBias)
    {
        int n = nums.size();
        int l = 0, r = n-1, i = -1;

        while(l <= r)
        {
            int mid = (l+r)/2;
            if(target > nums[mid])
            {
                l = mid + 1;
            }
            else if(target < nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                i = mid;
                if(leftBias)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return i;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);

        return {left, right};

        
    }
};
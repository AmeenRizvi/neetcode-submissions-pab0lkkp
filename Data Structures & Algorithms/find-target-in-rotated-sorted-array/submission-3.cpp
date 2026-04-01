class Solution {
    int binarySearch(int l, int r, vector<int>& nums, int target )
    {
        
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                r = mid-1;
            else 
                l = mid + 1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;

        while(l < r)
        {
            int mid = (l+r)/2;
            if(nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        int pivot = l;

        int result = binarySearch(0, pivot-1, nums, target);
        if(result != -1)
            return result;
        
        return binarySearch(pivot, n-1, nums, target);

        
    }
};

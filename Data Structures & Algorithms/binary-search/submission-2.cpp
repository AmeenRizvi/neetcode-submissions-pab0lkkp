class Solution {
    int binarySearch(int l, int r, vector<int>& nums, int target)
    {
        if(l > r)
        {
            return -1;
        }
        int mid = (l+r)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
        {
            return binarySearch(mid+1, r, nums, target);
        }
        else
        {
            return binarySearch(l,mid-1, nums, target);
        }

    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binarySearch(0, n-1, nums, target);
        
        
    }
};

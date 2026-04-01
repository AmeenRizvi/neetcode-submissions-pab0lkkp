class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n-1, ans = nums[0];

        while(l <= r)
        {
            if(nums[l] < nums[r])
            {
                ans = min(ans, nums[l]);
                break;
            }
            
            int mid = (l+r)/2;
            ans = min(ans, nums[mid]);
            
            if(nums[mid] >= nums[l])
            {
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return ans;
        
    }
};

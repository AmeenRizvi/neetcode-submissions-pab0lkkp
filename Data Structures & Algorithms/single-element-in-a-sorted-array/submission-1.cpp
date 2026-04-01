class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;

        while(l <= r)
        {
            int m = (l+r)/2;
            if((m-1 < 0 || nums[m-1] != nums[m]) && (m+1 == n || nums[m] != nums[m+1]) )
                return nums[m];

            int leftSize = (m-1 >= 0 && nums[m-1] == nums[m] ) ? m-1 : m;
            if(leftSize %2 == 1)
                r = m - 1;
            else
                l = m + 1;
        }

        return -1;
        
    }
};
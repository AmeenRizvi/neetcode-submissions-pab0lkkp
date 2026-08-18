class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        {
            return n;
        }
        int k = 1;

        for(int r = 1; r < n; r++)
        {
            if(nums[r] != nums[r-1])
            {
                nums[k] = nums[r];
                k++;
            }
        }
        return k;
        
    }
};
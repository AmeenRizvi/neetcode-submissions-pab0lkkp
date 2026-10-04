class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        int l = 2;
        for(int r = 2; r < n; r++)
        {
            if(nums[r] == nums[l-2])
            {
                continue;
            }
            nums[l] = nums[r];
            l++;
        }
        return l;
        
    }
};
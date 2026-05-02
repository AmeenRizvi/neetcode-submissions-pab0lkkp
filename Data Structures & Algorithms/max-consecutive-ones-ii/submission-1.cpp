class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int l = 0, zero = 0, maxLen = 0;

        for(int r = 0; r < n; r++)
        {
            if(nums[r] == 0)
            {
                zero++;
            }
            while(zero > 1)
            {
                if(nums[l] == 0) zero--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
        
    }
};

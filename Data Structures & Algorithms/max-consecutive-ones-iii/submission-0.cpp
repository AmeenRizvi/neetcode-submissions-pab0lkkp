class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, n = nums.size(), countZero = 0;
        int maxLen = 0;

        for(int r = 0; r < n; r++)
        {
            if(nums[r] == 0)
            {
                countZero++;
                while(countZero > k)
                {
                    if(nums[l] == 0)
                    {
                        countZero--;
                    }
                    l++;
                }
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
        
    }
};
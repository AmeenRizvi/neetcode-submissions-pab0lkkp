class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, countZero = 0, maxLen = 0;

        while(r < n)
        {
            if(nums[r] == 0)
            {
                countZero++;
                while(countZero > 1)
                {
                    if(nums[l] == 0)
                    {
                        countZero--;
                    }
                    l++;
                }
            }
            int len = r - l + 1;
            maxLen = max(maxLen, len);
            r++;
        }
        return maxLen;
        
    }
};

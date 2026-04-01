class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int maxLen = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            int mini = nums[i], maxi = nums[i];
            for(int j = i;  j < n; j++)
            {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                if(maxi-mini > limit)
                {
                    break;
                }
                maxLen = max(maxLen, j-i+1); 
            }
        }
        return maxLen;
        
    }
};
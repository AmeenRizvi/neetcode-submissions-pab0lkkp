class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int tSum = 0;
        for(int num : nums) tSum += num;
        int lSum = 0;
        
        for(int i = 0; i < n; i++)
        {
            int rSum = tSum - nums[i] - lSum;
            if(lSum == rSum)
            {
                return i;
            }

            lSum += nums[i];
        }
        return -1;

        
    }
};
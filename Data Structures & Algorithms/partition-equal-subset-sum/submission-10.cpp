class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for(int num : nums)
        {
            totalSum += num;
        }

        if(totalSum % 2 == 1)
        {
            return false;
        }
        int sum = totalSum / 2;

        // vector<vector<bool>>dp(n+1, vector<bool>(totalSum+1, false));
        vector<bool>row(sum+1, false);
        vector<bool>nextRow(sum+1, false);
        nextRow[sum] = true;


        for(int i = n-1; i >= 0; i--)
        {
            for(int s = sum; s >= 0; s--)
            {
                bool take = false;
                if(s + nums[i] <= sum)
                {
                    take = nextRow[s + nums[i]];
                }
                bool dontTake = nextRow[s];

                row[s] = take || dontTake;
            }
            nextRow = row;
        }
        return nextRow[0];
        
    }
};

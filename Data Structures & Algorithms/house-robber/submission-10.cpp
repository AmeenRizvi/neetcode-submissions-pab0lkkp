class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        // base case
        int twoHouseForw = 0, oneHouseForw = 0;

        for(int i = n-1; i >= 0; i--)
        {
            // dp[i] = max(nums[i] + dp[i+2], dp[i+1])
            int curHouseRob = max(nums[i] + twoHouseForw, oneHouseForw);

            // to iterate forward
            twoHouseForw = oneHouseForw;
            oneHouseForw = curHouseRob;
        }

        // Time Complexity : O(n)
        // Space complexity : O(1) extra space for variables
        return oneHouseForw;
        
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // Edge case
        if(n == 1) return nums[0];

        // money in second last house(i-2) and last house(i-1)
        int secondLastHouse = 0, lastHouse = 0;

        for(int i = 0; i < n; i++)
        {
            int curHouseRob = max(nums[i] + secondLastHouse, lastHouse);
            
            // swapping variables to iterate forward
            secondLastHouse = lastHouse;
            lastHouse = curHouseRob;
        }

        // Time complexity : O(n)
        // Space complexity : O(1) extra space for variables
        return lastHouse;
    }
};

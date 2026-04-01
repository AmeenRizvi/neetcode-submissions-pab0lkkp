class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>count;
        count[0] = 1;
        int prefixSum = 0, ans = 0;

        for(int num : nums)
        {
            prefixSum += num;
            if(prefixSum >= goal)
            {
                ans += count[prefixSum - goal];
            }
            count[prefixSum]++;
        }
        return ans;
        
    }
};
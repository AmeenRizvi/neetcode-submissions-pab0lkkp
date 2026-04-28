class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int runningSum = 0, count = 0;

        unordered_map<int, int>mp;
        mp[0] = 1;

        for(int i = 0; i < n; i++)
        {
            runningSum += nums[i];
            int diff = runningSum - k;
            if(mp.find(diff) != mp.end())
            {
                count += mp[diff];
            }
            mp[runningSum]++;
        }
        return count;
        
    }
};
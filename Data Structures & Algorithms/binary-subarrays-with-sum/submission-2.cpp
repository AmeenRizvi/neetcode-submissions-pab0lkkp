class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int>mp;
        mp[0] = 1;
        int runningSum = 0, ans = 0;

        for(int i = 0; i < n; i++)
        {
            runningSum += nums[i];
            int diff = runningSum - goal;
            if(mp.find(diff) != mp.end())
            {
                ans += mp[diff];
            }
            mp[runningSum]++;
        }
        return ans;
        
    }
};
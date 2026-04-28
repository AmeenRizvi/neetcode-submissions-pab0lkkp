class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        mp[0] = -1;
        int runningSum = 0;

        for(int i = 0; i < n; i++)
        {
            runningSum += nums[i];
            int remainder = runningSum % k;
            if(mp.find(remainder) == mp.end())
            {
                mp[remainder] = i;
            }
            else if(i - mp[remainder] >= 2)
            {
                return true;
            }
        }
        return false;
        
    }
};
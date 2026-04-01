class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        
        set<vector<int>>ans;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]--;
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            for(int j = i+1; j < n; j++)
            {
                mp[nums[j]]--;
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;

                int tar = -nums[i] - nums[j];
                if(mp[tar] > 0)
                    ans.insert({nums[i], nums[j], tar });
            }

            for(int j = i+1; j < n; j++)
                mp[nums[j]]++;
        }
        vector<vector<int>>res(ans.begin(), ans.end());
        return res;
        
    }
};

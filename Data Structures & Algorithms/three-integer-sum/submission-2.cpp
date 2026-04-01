class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>>res;

        for(int i = 0; i < n; i++)
        {
            int tar = -nums[i];
            int l = i+1, r = n-1;
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            while(l < r)
            {

                
                if(nums[l] + nums[r] == tar)
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l-1])
                        l++;
                }
                else if(nums[l] + nums[r] < tar)
                    l++;
                else
                    r--;
            }
        }
        return res;
        
    }
};

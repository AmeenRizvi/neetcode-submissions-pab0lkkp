class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1) return nums;
        int n = nums.size();
        vector<int>ans;
        int streak = 1;

        for(int i = 1; i < n; i++)
        {
            if(nums[i] != nums[i-1]+1)
            {
                streak = 1;
            }
            else
            {
                streak++;
            }

            if(i >= k-1)
            {
                if(streak >= k)
                {
                    ans.push_back(nums[i]);
                }
                else
                {
                    ans.push_back(-1);
                }
            }
        }
        return ans;

    }
};

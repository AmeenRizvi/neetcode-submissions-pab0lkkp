class Solution {
    vector<vector<int>>res;
    void backtrack(vector<int>& nums, int target, int sum ,vector<int>&ans,int i)
    {
        if(sum == target)
        {
            res.push_back(ans);
            return;
        }
        if(sum > target || i >= nums.size())
            return;
        
        ans.push_back(nums[i]);
        backtrack(nums, target, sum+nums[i], ans, i);
        ans.pop_back();
        backtrack(nums, target, sum, ans, i+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>ans;
        backtrack(nums, target, 0, ans, 0);
        return res;
    }
};

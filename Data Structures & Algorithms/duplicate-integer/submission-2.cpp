class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>numSet(nums.begin(), nums.end());
        return numSet.size() < nums.size();
        
    }
};
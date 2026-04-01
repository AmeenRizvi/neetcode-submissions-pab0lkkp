class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int start = nums[0], end = nums[n-1];
        unordered_set<int>s(nums.begin(), nums.end());
        for(int i = start; i <= end; i++)
        {
            if(s.find(i) == s.end())
            {
                k--;
                if(k == 0) return i;
            }
        }
        return k+end;
        
    }
};

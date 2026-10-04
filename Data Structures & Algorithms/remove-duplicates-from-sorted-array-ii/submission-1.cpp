class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>freq;
        int l = 0;
        int n = nums.size();

        for(int r = 0; r < n; r++)
        {
            freq[nums[r]]++;
            if(freq[nums[r]] > 2)
            {
                freq[nums[r]]--;
                continue;
            }
            nums[l] = nums[r];
            l++;
        }

        return l;
        
    }
};
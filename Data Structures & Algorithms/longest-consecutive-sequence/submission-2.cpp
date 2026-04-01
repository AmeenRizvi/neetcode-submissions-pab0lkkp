class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        int count = 1, maxCount = 1;
        for(int i = 1; i < n; i++)
        {
            cout << nums[i] << endl;
            if(nums[i] == nums[i-1])
                continue;
            if(nums[i] == nums[i-1]+1)
            {
                count++;
                maxCount = max(maxCount, count);
            }
            else
                count = 1;
        }
        return maxCount;
        
    }
};

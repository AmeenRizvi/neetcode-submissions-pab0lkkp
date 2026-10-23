class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, maxLen = 0;
        unordered_map<int,int>freq;

        while(r < n)
        {
            freq[nums[r]]++;
            while(freq[nums[r]] > k)
            {
                freq[nums[l]]--;
                if(freq[nums[l]] == 0)
                {
                    freq.erase(nums[l]);
                }
                l++;
            }
            int len = r-l+1;
            maxLen = max(maxLen ,len);
            r++;
        }
        return maxLen;

    }
};

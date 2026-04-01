class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<int>prefix(n+1, 0);

        for(int i = 0; i < n; i++)
        {
            prefix[i+1] = prefix[i] + (nums[i] == 0 ? 1 : 0);
        }

        for(int l = 0; l < prefix.size(); l++)
        {
            int low = l, high = n;
            while(low < high)
            {
                int mid = (low + high) / 2;
                if(prefix[mid+1] - prefix[l] <= k)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid;
                }
            }
            ans = max(ans, low - l);
        }
        return ans;
        
    }
};
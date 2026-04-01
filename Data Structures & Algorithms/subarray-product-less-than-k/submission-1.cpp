class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k <= 1) return 0;
        int n = nums.size();
        vector<double>logs(n+1, 0.0);
        double logK = log(k);

        for(int i = 0; i < n; i++)
        {
            logs[i+1] = logs[i] + log(nums[i]);
        }
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            int l = i + 1, r = n + 1;
            while(l < r)
            {
                int mid = l - (l-r)/2;
                if(logs[mid] < logs[i] + logK - 1e-12)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            ans += l - (i+1); 
        }
        return ans;
        
    }
};
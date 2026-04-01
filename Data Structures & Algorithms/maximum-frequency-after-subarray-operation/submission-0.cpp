class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int cntK = 0;
        for(int num : nums)
        {
            if(num == k)
                cntK++;
        }
        int ans = 0;

        for(int i = 1; i <= 50; i++)
        {
            if(i == k) continue;
            int cnt = 0;

            for(int num : nums)
            {
                if(num == i) cnt++;
                if(num == k) cnt--;

                cnt = max(cnt, 0);
                ans = max(ans, cntK + cnt);
            }
        }
        return ans;
        
    }
};
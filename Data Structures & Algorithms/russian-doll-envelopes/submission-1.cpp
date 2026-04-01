class Solution {
    vector<int>nums, memo;
    int n;
    int solve(int i)
    {
        if(memo[i] != -1)
            return memo[i];
        int lis = 1;
        for(int j = i + 1; j < n; j++)
        {
            if(nums[i] < nums[j])
            {
                lis = max(lis, 1 + solve(j));
            }
        }
        return memo[i] = lis;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b)
        {
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        });
        nums.resize(n);
        for(int i = 0; i < n; i++)
        {
            nums[i] = envelopes[i][1];
        }
        memo.assign(n, -1);

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res = max(res, solve(i));
        }
        return res;
    }
};
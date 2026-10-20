class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans(n, 0);
        if(k == 0)
        {
            return ans;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= abs(k); j++)
            {
                ans[i] += code[(i+ (k > 0 ? j : -j)+n)%n ];
            }
        }
        return ans;

    }
};

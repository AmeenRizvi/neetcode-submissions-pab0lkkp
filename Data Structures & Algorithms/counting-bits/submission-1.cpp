class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1, 0);

        for(int num = 1; num <= n; num++)
        {
            int c = 0;
            for(int i = 0; i < 32; i++)
            {
                if(num &(1 << i))
                {
                    c++;
                }
            }
            ans[num] = c;
        }
        return ans;
        
    }
};

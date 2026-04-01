class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0;

        int l = 0;
        for(int r = 1; r < n; r++)
        {
            if(prices[l] < prices[r])
            {
                res = max(res, prices[r]-prices[l]);
            }
            else
            {
                l = r;
            }
        }
        return res;
        
    }
};

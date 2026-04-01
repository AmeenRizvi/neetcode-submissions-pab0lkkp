class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int smallest = INT_MAX, secondSmallest = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(smallest > prices[i])
            {
                secondSmallest = smallest;
                smallest = prices[i];
            }
            else if(secondSmallest > prices[i])
            {
                secondSmallest = prices[i];
            }
        }

        int amount = smallest + secondSmallest;
        int leftOver = money-amount;
        if(leftOver < 0) return money;
        return leftOver;
        
    }
};
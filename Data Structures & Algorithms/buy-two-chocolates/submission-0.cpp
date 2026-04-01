class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        sort(prices.begin(), prices.end());
        int amount = prices[0] + prices[1];
        int leftOver = money-amount;
        if(leftOver < 0) return money;
        return leftOver;
        
    }
};
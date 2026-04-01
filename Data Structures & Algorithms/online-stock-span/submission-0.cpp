class StockSpanner {
    vector<int>stockPrice;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        stockPrice.push_back(price);
        int count = 0;
        for(int i = stockPrice.size()-1; i >= 0; i--)
        {
            if(stockPrice[i] > price)
            {
                break;
            }
            count++;
        }
        return count;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
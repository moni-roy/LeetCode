class StockSpanner {
private:
    stack<pair<int, int> > stk;
public:
    StockSpanner() {
        while(!stk.empty()) stk.pop();
    }
    
    int next(int price) {
        int cur = 1;
        while (!stk.empty() && stk.top().first <= price) {
            cur += stk.top().second;
            stk.pop();
        }
        stk.push({price, cur});
        return cur;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prev = 0, buy = INT_MIN, sell = INT_MIN;
        for (auto p : prices) {
            int pre_sell = sell;
            sell = buy + p;
            buy = max(prev - p, buy);
            prev = max(pre_sell, prev);
        }
        return max(prev, sell);
    }
};
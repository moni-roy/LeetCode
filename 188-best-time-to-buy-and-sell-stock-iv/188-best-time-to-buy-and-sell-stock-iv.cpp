class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int res = 0, len = prices.size();
        if (len < 2) return 0;
        if (k >= len / 2) {
            for (int i = 1; i < len; ++i) {
                if (prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
            }
            return res;
        }
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for (int i = 0; i < len; ++i) {
            for (int j = 1; j <= k; ++j) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};
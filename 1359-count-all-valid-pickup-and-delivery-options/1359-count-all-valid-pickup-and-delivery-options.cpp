class Solution {
public:
    int countOrders(int n) {
        long long res = 1;
        for (int i = 1; i <= n; ++i) {
            res = res * (2 * i - 1) * i % 1000000007;
        }
        return res;   
    }
};
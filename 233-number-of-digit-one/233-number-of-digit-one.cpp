class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long long m = 1; m <= n; m *= 10) {
            long long a = m * 10;
            res += (n / a) * m + min(max(n % a - m + 1, 0LL), m);
        }
        return res;
    }
};
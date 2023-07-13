class Solution {
    const int mod = 1e9 + 7;
public:
    int concatenatedBinary(int n) {
        if (n == 1) return 1;
        int prev = concatenatedBinary(n - 1);
        int len = 0, cur = n;
        while (cur) {
            prev *= 2;
            prev %= mod;
            cur /= 2;
        }
        prev += n;
        return prev % mod;
    }
};
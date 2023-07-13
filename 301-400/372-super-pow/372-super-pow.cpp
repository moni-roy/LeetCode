class Solution {
private:
    int mod = 1337;
    int bigMod(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int last = b.back();
        b.pop_back();
        a %= mod;
        return bigMod(superPow(a, b), 10) % mod * bigMod(a, last) % mod;
    }
};
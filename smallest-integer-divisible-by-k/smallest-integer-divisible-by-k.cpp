class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_map<int, int> m;
        int n = 1, mod = 1;
        while (mod % k) {
            mod = (mod * 10 + 1) % k;
            if (m.count(mod)) return -1;
            m[mod] = n;
            n++;
        }
        return n;
    }
};
class Solution {
public:
    int findComplement(int num) {
        int bits = 0;
        int n = num;
        while (n) {
            n = n >> 1;
            bits++;
        }
        long long mask = (long long) (1 << bits) - 1;
        return num ^ mask;
    }
};
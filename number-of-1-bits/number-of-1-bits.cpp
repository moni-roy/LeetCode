class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n) {
            ret += n%2;
            n = n/2;
        }
        return ret;
    }
};
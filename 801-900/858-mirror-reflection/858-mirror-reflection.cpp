// https://leetcode.com/problems/mirror-reflection/discuss/2376155/Daily-LeetCoding-Challenge-August-Day-4/1524500
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int gcd = __gcd(p, q);
        p /= gcd;
        q /= gcd;

        if (q % 2 == 0) return 0;
        if (p % 2 == 0) return 2;
        return 1;
    }
};
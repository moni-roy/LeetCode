class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0; a*a <= c; a++) {
            double b = sqrt(c - a*a);
            if(b == long(b)) return true;
        }
        return false;
    }
};
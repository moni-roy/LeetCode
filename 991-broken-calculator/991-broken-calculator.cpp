class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int res = 0;
        while (startValue < target) {
            res++;
            if (target % 2 == 0) {
                target /= 2;
            } else {
                target++;
            }
        }
        return res + startValue - target;
    }
};
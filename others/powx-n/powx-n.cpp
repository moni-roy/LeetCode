class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        while(n) {
            if(n&1) ans = (n<0)?ans/x:ans*x;
            n = n/2;
            x*=x;
        }
        return ans;
    }
};
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n < 0) {
            N = -N;
            x = 1 / x;
        }
        double ans = 1;
        while(N) {
            if(N & 1) ans = ans * x;
            N = N / 2; 
            x *= x;
        }
        return ans;
    }
};
class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
       long long int l = 1, r = 1e9;
        int ans = 0;
        while( l <= r) {
            long long m = (l+r)/2;
            if(m*m > x) r = m - 1;
            else {
                if((m+1)*(m+1)>x) return m;
                l = m + 1;
            }
        }
        return ans;
    }
};
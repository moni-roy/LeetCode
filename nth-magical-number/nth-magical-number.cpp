class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int l = a / __gcd(a,b) * b;
        int m = l/a + l/b - 1;
        int q = n/m, r = n%m;
        long long ans = (long long)q * l  % (long long)(1e9+7);
        // cout<<l<<" "<<m<<" "<<q<<" "<<ans<<" "<<r<<endl;
        if(r == 0) return ans;
        int ca = a, cb = b;
        for(int i = 1; i<r;i++) {
            if(ca <= cb) {
                ca += a;
            }
            else cb += b;
        }
        ans += min(ca, cb);
        return ans % (long long)(1e9+7);
    }
};
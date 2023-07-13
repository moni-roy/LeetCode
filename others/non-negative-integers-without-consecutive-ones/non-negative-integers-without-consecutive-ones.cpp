class Solution {
public:
    int findIntegers(int n) {
        vector<int> fib(32);
        fib[0] = 1;
        fib[1] = 2;
        for(int i = 2; i<32; i++) fib[i] = fib[i-1] + fib[i-2];
        
        int ans = 0, k = 31, pb = 0;
        while(k>=0) {
            if(n & (1<<k)){
                ans += fib[k];
                if(pb) return ans;
                pb = 1;
            } else pb = 0;
            k--;
        }
        return ans+1;
    }
};
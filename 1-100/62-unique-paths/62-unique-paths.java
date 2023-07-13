public class Solution {
    
    //math solution: total number of permuation of m-1 downs and n-1 rights which is (m+n)!/(m!*n!)
    public int uniquePaths(int m, int n) {
        if(m==0||n==0) return 0;
        if(m==1 || n==1) return 1;
        
        m = m-1;
        n = n-1;
        
        return nCr(m+n, Math.min(m,n));
    }
    
    private int nCr (int n, int r) {
        long long_result = 1;
        for (int i = 0; i != r; i++) {
            // from n - r + 1 (when i = 0) to n (when i = r - 1)
            long_result *= (n - r + 1 + i);
            // from 1 (when i = 0)         to r (when i = r - 1)
            long_result /= (i + 1);
        }
        return (int) long_result;
    }
}